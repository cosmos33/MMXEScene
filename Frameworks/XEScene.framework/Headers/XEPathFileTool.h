/******************************************************************************

@File         XEPathFunc.h

@Version       1.0

@Created      2017, 6, 14

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/

#ifndef _XE_PATHFUNC_H_
#define _XE_PATHFUNC_H_

#include <vector>
#include <string>
#include "XPlatform.h"
#include "XString.h"

using std::vector;
using std::string;

//will not actually operate the files.
namespace XEPathFileTool
{
	// whether file or filePath is exist 
	bool IsFileOrDirExist(const char* pathname);
	// get files from path with suffix name.
	std::vector<std::string> GetFileWithExt(const char* path, const char* ext);
	// delete dir by using sys command without QT,if want to use QT function,please use 'XEFileHelper::removePath'
	bool DeleteDir(const char* pathname);
	// delete dir by using sys command without QT,if want to use QT function,please use 'XEFileHelper::removePath'
	bool Deletefile(const string &strFilePath);
	void GetAllFormatFiles(string fileFolderPath, vector<string>& files, string fileExtension);
	// copy file by using sys command without QT,if want to use QT function,please use 'XEFileHelper::CopyFileToPath'
	bool Copyfile(const string &strFromPath, const string &strToPath);
	
	bool CreateFolderByPath(const char* path);

	// if reverse is true, convert to '/', otherwise '\'
	void NormalPath(string& strFullName, bool reverse = true);
	void NormalPath(char *pFullName, bool reverse = true);
    void NormalPath(XString& pFullName, bool reverse = true);
	// Encode path/ Decode path
	void EncodePath(const string &strKey, string &strpath);
	void DecodePath(const string &strKey, string &strpath);
	// get application path, not support Android,please use JNI AssetManager or other function.
	string GetAppPath();
	// get dir from full name.
	string GetPathDir(const string &strFullName);
	// get fileName with suffix name from Full name.
	string GetFileName(const string& strFullName);
	// get Suffix name
	string GetFileExt(const std::string &strName);
	// trim Suffix name
	string GetFilePathExceptExt(const std::string &strName);
	// get relative path
	bool GetRaletivePath(const string &strFullPath, const string &strParentPath, string &strRelativePath);
	// whether is relative path
	bool IsRaletivePath(const string &strFullPath, const string &strParentPath);
	// simplify path, for example, convert 'root/bb/../aa' to 'root/aa' 
	void ExpandPath(string &strPath);
	// split string
	void SplitString(const string &str, const string &mak, vector<string> &vstr);
	// trim blank chars at both ends
	const string& Strtrim(string &s);

};

#endif


