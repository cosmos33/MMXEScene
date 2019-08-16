//
//  XESFileUtils.hpp
//  FaceDecorationKit
//
//  Created by HongjieFu on 2018/7/26.
//

#ifndef XESFileUtils_hpp
#define XESFileUtils_hpp

#include "XESDefine.h"
#include "xcommon/XTypes.h"
#include "xcommon/XString.h"
#include "xcommon/XArray.h"


XESS_HIDE_START

class XESData {
public:
    XESData():_bytes(NULL),_size(0){};
    
    virtual ~XESData();

    void Resize(size_t size);

    size_t GetSize() const;

    virtual unsigned char *Buffer() const;


private:
    unsigned char *_bytes;
    size_t _size;
};

XESS_HIDE_END


class FileUtils {

public:

    static xbool AddSearchPath(const char *cRelativePath);

    static void RemoveSearchPath(const char *cRelativePath);

    static xbool FileExists(const xchar *xcFileName);

    static const XString JSONBuffer(const xchar *xcFileName);

    static const XString FullFilePath(const xchar *xcFileName);

    static const XString FilePath(const xchar *xcFileName);

    static xbool GetDataFromFile(const xchar *xcFileName,XESData &data);

    static xbool Unzip(std::string zipFile, std::string unzipDir);
    
public:
    static XArray<XString> m_SearchPaths;

private:
    friend class Director;
};

#endif /* XESFileUtils_hpp */
