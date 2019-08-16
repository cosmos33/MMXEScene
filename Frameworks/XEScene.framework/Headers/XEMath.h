/******************************************************************************

@File         XEMath.h

@Version       1.0

@Created      2017, 10, 12

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/

#ifndef _XE_MATH_H_
#define _XE_MATH_H_
#include "XTypes.h"
#include "XMath3D.h"
#include "XGlobalFuncs.h"
#include <limits>

// Aux constants.
#undef  PI
#define PI 			        (3.1415926535897932f)
#define INV_PI			    (0.31830988618f)
#define HALF_PI			    (1.57079632679f)
#define SMALL_NUMBER	    (1.e-8f)//small enough
#define KINDA_SMALL_NUMBER	(1.e-4f)//a kind of small number
#define DELTA			    (0.00001f)// Magic numbers for numerical precision.

template <class T>
inline bool Equals(T lhs, T rhs) { return lhs + std::numeric_limits<T>::epsilon() >= rhs && lhs - std::numeric_limits<T>::epsilon() <= rhs; }

static const float M_EPSILON = 0.001f;
template <class T>
inline bool EqualsNotPrecison(T lhs, T rhs) { return lhs + M_EPSILON >= rhs && lhs - M_EPSILON <= rhs; }

//z is the forward vector of our camera. so the euler angle is Pitch.
namespace XEMath
{
	class LineSegment3
	{
	public:
		LineSegment3() :m_origin(0.f), m_direction(0.f){}
		LineSegment3(const XVECTOR3& origin, const XVECTOR3& direction) :m_origin(origin), m_direction(direction){}
	public:
		// get a point from a segment. t is the segment scale position(0~1)
		void GetPoint(XVECTOR3& point, xfloat32 t) const;
		// get lenght of this segment
		xfloat32 GetLength() const;
	public:
		XVECTOR3 m_origin;		//(m_origin, m_origin + m_direction)
		XVECTOR3 m_direction;	//direction with length.
	};

	xfloat32    InvSqrt(xfloat32 fNumber);
	xfloat32    FastAsin(xfloat32 Value);
	xfloat32    ClampAxis(xfloat32 radian);// returns radians in the range [0,2*PI)
	xfloat32    NormalizeAxis(xfloat32 radian);// returns radians in the range (-PI,PI]
	xfloat32    Xmod(xfloat32 X, xfloat32 Y);
	xfloat32    Atan2(xfloat32 Y, xfloat32 X);// y/x
	xfloat32    AreaOfTriangle(XVECTOR2 v1, XVECTOR2 v2, XVECTOR2 v3);//return 0 if can't be a triangle.
	xbool       IsNegativeFloat(const xfloat32& A);
	xbool       IsNaN(xfloat32 A);
	/** Return true if value is finite (not NaN and not Infinity). */
	xbool       IsFinite(xfloat32 A);
	/**
	*	Checks if a floating point number is nearly zero.
	*	@param Value			Number to compare
	*	@param ErrorTolerance	Maximum allowed difference for considering Value as 'nearly zero'
	*	@return					true if Value is nearly zero
	*/
	xbool		IsNearlyZero(xfloat32 Value, xfloat32 ErrorTolerance = SMALL_NUMBER);

	void        SinCos(xfloat32* ScalarSin, xfloat32* ScalarCos, xfloat32  Value);
	void        QuaternionToEuler(const XQUATERNION& quat, xfloat32& fRoll, xfloat32& fYaw, xfloat32& fPitch);
	void        EulerToMatrix(xfloat32 fRoll, xfloat32 fYaw, xfloat32 fPitch, XMATRIX4& mat);
	void        EulerToQuaternion(xfloat32 fRoll, xfloat32 fYaw, xfloat32 fPitch, XQUATERNION& quat);
	void        DirAndUpToQuaternion(const XVECTOR3& vForwardDir, const XVECTOR3& vUp, XQUATERNION& quat);
	void        QuaternionToDirAndUp(const XQUATERNION& quat, XVECTOR3& vForwardDir, XVECTOR3& vUp);
	void        LocationDirAndUpToMatrix(const XVECTOR3& vLocation, const XVECTOR3& vForwardDir, const XVECTOR3& vUp, XMATRIX4& mat4);
	void        MatrixToLocationAndDirAndUp(const XMATRIX4& mat4, XVECTOR3& vLocation, XVECTOR3& vForwardDir, XVECTOR3& vUp);
	XVECTOR3    GetScaleFromMatrix(const XMATRIX4& mat);
	XQUATERNION GetQuaternionFromMatrix(const XMATRIX4& mat);
	XMATRIX4    GetMatrixFromQuaternion(const XQUATERNION& quat);
	void        EliminateScaleFromMatrix(XMATRIX4& mat);
	void        EliminateRotateFromMatrix(XMATRIX4& mat);
	void		EliminateTranslateFromMatrix(XMATRIX4& mat);
	XMATRIX4    GenerateTranslateMatrixForVector(const XVECTOR3& vTranslate);
	XMATRIX4    GenerateScaleMatrixForVector(const XVECTOR3& vScale, XVECTOR3 vOriginPoint = XVECTOR3(0.f));
	void        RotateMatrixWorld(XMATRIX4& mat, const XQUATERNION& quat);
	void        ScaleMatrixWorld(XMATRIX4& mat, const XVECTOR3& vScale);
	XVECTOR3    RotateVector(const XQUATERNION& quat, const XVECTOR3&vec);
	XVECTOR3    UnrotateVector(const XQUATERNION& quat, const XVECTOR3& vec);
	xbool       Is2MatrixClosed(const XMATRIX4& mat1, const XMATRIX4& mat2, float fEpsilon = 1.e-6f);
	XMATRIX4    GenerateOrthoProjMatrix(xfloat32 fLeft = -1.f, xfloat32 fRight = 1.f, xfloat32 fButtom = -1.f, xfloat32 fTop = 1.f, xfloat32 fNear = -1.f, xfloat32 fFar = 100.f);
	XVECTOR2    GenerateMostNearSizeWithRate(const XVECTOR2& vOriginSize, xfloat32 fSizeRate, xint32 nStepSize = 1.f);
	xint32		ComputerMin2nSubSquare(xint32 nSize);
	
	template<typename T = xfloat32>
	void        MakeRoundingNumberT(T& inputVal)
	{
		inputVal = inputVal >= 0.f ? floor(inputVal + .5f) : ceil(inputVal - .5f);
	}

	template<typename T>
	void        MakeRoundingNumberM1D(T& inputVal, xint32 n = -1)//number structure with the "m", 1D, specify the exact count of number that you want to make,-1 is all.
	{
		xint32 nMaxCount = sizeof(inputVal.m) / sizeof(inputVal.m[0]);
		n = -1 == n ? nMaxCount : X_ClampRet(n, 0, nMaxCount);
		for (xint32 i = 0; i < n; ++i)
			MakeRoundingNumberT(inputVal.m[i]);
	}

    XVECTOR2 GetVerticalDirFor2DLine(const XVECTOR2& vLineSegDir, const XVECTOR2& vPointInLine);
	//nearest-sliding-Interpolation
	//will alloc memory here.
	xuint8*     GenerateMin2nLinearInterpTexData(const xuint8* data, xint32 nWidth, xint32 nHeight, xint32 nChannelCount, xint32* pN2W = NULL, xint32* pN2H = NULL);
	// stretch data to what you want. 
	xbool       StrechLinearInterpTexData(xuint8* dst, const xuint8* src, xint32 srcW, xint32 srcH, xint32 dstW, xint32 dstH, xint32 nChannelCount = 1);
	/************************************************************************/
	// To calculate the intersection point in a plane for a ray-line with specific origin point and its dir.
	// vLineOriginPoint: original point of the ray.
	// vLineDir: directional vector of the ray.
	// vPlanePoint: the specific point in the plane.
	// vPlaneDir: the specific dir of the plane.
	/************************************************************************/
	xbool	    CalculatePlaneWithLineIntersection(const XVECTOR3& vLineOriginPoint,
		const XVECTOR3& vLineDir,
		const XVECTOR3& vPlanePoint,
		const XVECTOR3& vPlaneDir, XVECTOR3& vResult);
	/************************************************************************/
	// To calculate the intersection point of two vectors. 
	// lineCrossPostion, to hold the scale position in these two lines.
	// bTestSegLineCrossOnly, to test whether these two lines are crossed or not only.
	// fTolerance, the tolerance of the calculation.
	// return, see the enum below.
	/************************************************************************/
	enum{MATH_SEG_COINCIDE, MATH_SEG_CROSS, MATH_SEG_PARALLEL};
	xint32      CalculateSegmentLineCross(
		XVECTOR3& out, 
		const LineSegment3& line1, 
		const LineSegment3& line2, 
		XVECTOR2* lineCrossPostion = NULL, 
		xbool bTestSegLineCrossOnly = xfalse,
		xfloat32 fTolerance = 0.000001f);

	//get cross point of the 4-edge shape.
	//return, XVECTOR2: the cross-points
	//line1:(l,t),(l+w,t)
	//line2:(l+w,t),(l+w,t+h)
	//line3:(l+w,t+h),(l,t+h)
	//line4:(l,t+h),(l,t)
	XArray<XVECTOR2> GetCrossPointOf2DEdge(const XVECTOR2& vLineOrigin, const XVECTOR2& vLineDir, xfloat32 l, xfloat32 t, xfloat32 w, xfloat32 h);

	/************************************************************************/
	//2D:Determine if the point is inside the convex  polygon
	//aPoints:the points in the convex polygon 
	/************************************************************************/	
	xbool	IsPointInConvexPolygon(const XArray<XVECTOR2>& aPoints,const XVECTOR2& vTarget);
	/************************************************************************/
	//Determine if the point is inside the triangle,default contains point on the edge
	//bContrainEdge:whether contains points on the edge
	/************************************************************************/
	xbool	IsPointInTriangle(const XVECTOR2& v1, const XVECTOR2& v2, const XVECTOR2& v3, const XVECTOR2& vTarget,xbool bContrainEdge = xtrue);

	/************************************************************************/
	// Barycentric Coordinates in 2D
	// p = a + m * (b - a) + n * (c - a) = (1 - m - n) * a + m * b + n * c
	// p is a point in triangle, and a,b,c is three points of triangle
	/************************************************************************/
	xbool   CalculateBarycentricCoord(XVECTOR2 vPos1,XVECTOR2 vPos2,XVECTOR2 vPos3,XVECTOR2 vP,xfloat32& nI,xfloat32& nJ,xfloat32& nK);
};

#endif


