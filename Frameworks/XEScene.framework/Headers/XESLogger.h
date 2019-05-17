//
// Created by HongjieFu on 2019-04-18.
//

#ifndef PODS_XESLOGGER_H
#define PODS_XESLOGGER_H


#include <functional>

typedef std::function<void(const char *)> XELuaPrintFunc;

class XESLogger {
public:
    static XESLogger *GetInstance();

    void PrintLog(const char *format, ...);

    void PrintErr(const char *format, ...);

    inline void SetPrintFunc(const XELuaPrintFunc &func) {
        this->m_PrintFunc = func;
    }

    inline void SetErrFunc(const XELuaPrintFunc &m_ErrFunc) {
        this->m_ErrFunc = m_ErrFunc;
    };

    inline void SetEnable(const bool &enable) {
        this->m_Enable = enable;
    }

private:

    XESLogger();

    ~XESLogger();

    XELuaPrintFunc m_PrintFunc;
    XELuaPrintFunc m_ErrFunc;

    char *m_LogBuffer;

    bool m_Enable;
};


#endif //PODS_XESLOGGER_H
