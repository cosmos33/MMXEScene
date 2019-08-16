/******************************************************************************

@File         XEALDelaunayTriangleGenerator.h

@Version       1.0

@Created      2019, 6, 13

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/

#ifndef _XE_AL_DELAUNAY_TRIANGLE_GENERATOR_H_
#define _XE_AL_DELAUNAY_TRIANGLE_GENERATOR_H_
#include "XTypes.h"
#include "XMath3D.h"
#include "XArray.h"
#include "XCustomGeometry.h"

#define ALDT_MINSAMPLE	3

/**
* Utility class for XEALDelaunayTriangleGenerator
* This represents Points in XEALDelaunayTriangleGenerator
*/

struct XETriangle;
struct XETrianglePoint
{
	XETrianglePoint() :Position(0){}
	XETrianglePoint(XVECTOR3 Pos) : Position(Pos) {}
	// position of Point
	XVECTOR3 Position;
	// Triangles this point belongs to
	XArray<XETriangle*> Triangles;
	bool operator==(const XETrianglePoint& Other) const;
	void AddTriangle(XETriangle * NewTriangle);
	void RemoveTriangle(XETriangle * TriangleToRemove);
	float GetDistance(const XETrianglePoint& Other);
};

struct XETrianglePointWithIndex
{
	XETrianglePoint Point;
	xint32 OriginalIndex;
	XETrianglePointWithIndex() :OriginalIndex(0){}
	XETrianglePointWithIndex(const XETrianglePoint& P, xint32 InOriginalIndex)
		: Point(P),
		OriginalIndex(InOriginalIndex)
	{
	}
};

struct XETriangleHalfEdge
{
	XETriangleHalfEdge();
	XETriangleHalfEdge(XETrianglePoint * A, XETrianglePoint * B);
	// 3 vertices in CCW order
	XETrianglePoint* Vertices[2];
	bool DoesShare(const XETriangleHalfEdge& A) const;
	bool operator==(const XETriangleHalfEdge& Other) const;
};

struct XETriangle
{
	XETriangle(XETriangle & Copy);
	XETriangle(XETrianglePoint * A, XETrianglePoint * B, XETrianglePoint * C);
	XETriangle(XETrianglePoint * A);
	XETriangle(XETrianglePoint * A, XETrianglePoint * B);
	XETriangle();
	~XETriangle();

	// 3 vertices in CCW(counter-clockwise) order
	XETrianglePoint* Vertices[3];
	// average points for Vertices
	XVECTOR3	Center;
	// FEdges
	XETriangleHalfEdge Edges[3];

	bool operator==(const XETriangle& Other) const;

	bool Contains(const XETrianglePoint& Other) const;

	float GetDistance(const XETrianglePoint& Other) const;

	float GetDistance(const XVECTOR3& Other) const;

	bool HasSameHalfEdge(const XETriangle* Other) const;

	bool DoesShareSameEdge(const XETriangle* Other) const;

	// find point that doesn't share with this
	// this should only get called if it shares same edge
	XETrianglePoint * FindNonSharingPoint(const XETriangle* Other) const;

private:
	void MakeCCW();
};


/**
* Generates triangles from sample point using Delaunay Triangulation,
* TriangleList contains the list of triangle after generated.
*/

class XEALDelaunayTriangleGenerator
{
public:
	XEALDelaunayTriangleGenerator();
	~XEALDelaunayTriangleGenerator();

	enum ECircumCircleState
	{
		ECCS_Outside = -1,
		ECCS_On = 0,
		ECCS_Inside = 1,
	};
	/**
	* Reset all data
	*/
	void Reset();
	void EmptyTriangles();
	void EmptySamplePoints();

	/**
	* Generate triangles from SamplePointList
	*/
	void Triangulate();

	/**
	* Add new sample point to SamplePointList and its corresponding sample index in the blendspace
	* It won't be added if already exists
	*/
	void AddSamplePoint(const XVECTOR3& NewPoint, const xint32 SampleIndex);

	/**
	* Sort SamplePointList in the order of 1) -X->+X 2) -Y->+Y 3) -Z->+Z
	* Sort Point of the input point in the order of
	* 1) -> +x. 2) -> +y, 3) -> +z
	* by that, it will sort from -X to +X, if same is found, next will be Y, and if same, next will be Z
	*/
	void SortSamples();

	/**
	* Get TriangleList
	*/
	const XArray<XETriangle*> & GetTriangleList() const;

	/**
	* Get SamplePointList
	*/
	const XArray<XETrianglePoint> & GetSamplePointList() const;

	void EditPointValue(xint32 SamplePointIndex, XVECTOR3 NewValue);

	/** Original index - before sorted to match original data **/
	xint32 GetOriginalIndex(xint32 NewSortedSamplePointList) const;

	const XArray<xint32>& GetIndiceMapping();

	//suitable for lua side.
	xbool GetTrianglePointIndices(XETriangle* pTriangle, xint32& i1, xint32& i2, xint32& i3);

	/* Set the grid box, so we can normalize the sample points */
	void SetGridBox(xfloat32 fMinX, xfloat32 fMaxX, xfloat32 fMinY, xfloat32 fMaxY );

private:
	/**
	* The key function in Delaunay Triangulation
	* return true if the TestPoint is WITHIN the triangle circumcircle
	*	http://en.wikipedia.org/wiki/Delaunay_triangulation
	*/
	ECircumCircleState GetCircumcircleState(const XETriangle* T, const XETrianglePoint& TestPoint);

	/**
	* return true if they can make triangle
	*/
	xbool IsEligibleForTriangulation(const XETrianglePoint* A, const XETrianglePoint* B, const XETrianglePoint* C);

	/**
	* return true if 3 points are collinear
	* by that if those 3 points create straight line
	*/
	xbool IsCollinear(const XETrianglePoint* A, const XETrianglePoint* B, const XETrianglePoint* C);

	/**
	* return true if all points are coincident
	* (i.e. if all points are the same)
	*/
	xbool AllCoincident(const XArray<XETrianglePoint>& InPoints);

	/**
	* Flip TriangleList(I) with TriangleList(J).
	*/
	xbool FlipTriangles(const xint32 TriangleIndexOne, const xint32 TriangleIndexTwo);

	/**
	* Add new Triangle
	*/
	void AddTriangle(XETriangle & newTriangle, xbool bCheckHalfEdge = xtrue);

	/**
	* Used as incremental step to triangulate all points
	* Create triangles TotalNum of PointList
	*/
	xint32 GenerateTriangles(XArray<XETrianglePoint> & PointList, const xint32 TotalNum);

private:
	/**
	* Data Structure for triangulation
	* SamplePointList is the input data
	*/
	XArray<XETrianglePoint>		SamplePointList;
	/**
	* This stores the indices from the added sample points to the original indices in the blendspace
	*/
	XArray<xint32>			IndiceMappingTable;

	/**
	* Output data for this generator
	*/
	XArray<XETriangle*>	TriangleList;

	/**
	* We need to normalize the points before the circumcircle test, so we need the extents of the grid.
	* Store 1 / GridSize to avoid recalculating it every time through GetCirculcircleState
	*/
	XVECTOR3				GridMin;
	XVECTOR3				RecipGridSize;
};

#endif


