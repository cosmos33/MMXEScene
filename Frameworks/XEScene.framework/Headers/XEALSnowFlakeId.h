/******************************************************************************

@File         XEALSnowFlakeId.h

@Version       1.0

@Created      2019, 5, 27

@Description  The class ids of each class in X Editor, Algorithm from TWitter.
			  reference to 
			  https://gavinlee1.github.io/2017/06/28/%E5%B8%B8%E8%A7%81%E5%88%86%E5%B8%83%E5%BC%8F%E5%85%A8%E5%B1%80%E5%94%AF%E4%B8%80ID%E7%94%9F%E6%88%90%E7%AD%96%E7%95%A5%E5%8F%8A%E7%AE%97%E6%B3%95%E7%9A%84%E5%AF%B9%E6%AF%94/
			  0-0000000000 0000000000 0000000000 0000000000 0(41 bits, milliseconds)
			  00000(5bits, data center id)
			  00000(5bits, worker id)
			  000000000000(12 bits, count in the milliseconds)

@HISTORY:

******************************************************************************/


#ifndef _XE_GUID_SNOW_FLAKE_H_
#define _XE_GUID_SNOW_FLAKE_H_
#include "XTypes.h"
#include "XString.h"
//AL is short for algorithm.

class XEALSnowFlakeId
{
protected:
	XEALSnowFlakeId();
private:
	xint64         m_nStartTime;
	xint64         m_nWorkerIdBits;
	xint64         m_nDataCenterIdBits;
	xint64         m_nMaxWorkerId;
	xint64         m_nMaxDataCenterId;
	xint64         m_nSequenceBits;
	xint64         m_nWorkerIdMoveBits;
	xint64         m_nDataCenterIdMoveBits;
	xint64         m_nTimestampMoveBits;
	xint64         m_nSequenceMask;
	xint64         m_nWorkerId;
	xint64         m_nDataCenterId;
	xint64         m_nSequence;
	xint64         m_nLastTimestamp;
	xint64         m_nBaseTimeline;//T(in second) *1000 - X(system interval, in millisceond) = BaseTimeline; T(in millisecond) = BaseTimeline + X'
public:
	enum ConvertType
	{
		CT_HEX,
		CT_BINARY
	};
	xbool                   SetupSnowFlakeIdGenerator(xint64 nWorkerId, xint64 nDataCenterId);
	xint64                  NextId();
	XString                 ToString(xint64 nId, ConvertType eCT = CT_HEX);
	xint64                  FromString(const xchar* szIdStr, ConvertType eCT = CT_HEX);
public:
	static xint64           GetNextId();
	static XString          ConvertIdToString(xint64 nId, ConvertType eCT = CT_HEX);
	static xint64           ConvertStringToId(const xchar* nIdStr, ConvertType eCT = CT_HEX);
	static XEALSnowFlakeId *GetInstance();
private:
	xint64                  BlockTillNextMillisecond(xint64 nLastTimestamp);
	xint64                  CurrentTime();
	
};


#endif//_XE_GUID_SNOW_FLAKE_H_