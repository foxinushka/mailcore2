//
//  MCNetService.cpp
//  mailcore2
//
//  Created by Robert Widmann on 4/28/13.
//  Copyright (c) 2013 MailCore. All rights reserved.
//

#include "MCNetService.h"

using namespace mailcore;

void NetService::init()
{
    mHostname = NULL;
    mPort = 0;
    mConnectionType = ConnectionTypeClear;
    mSuggestedAuthType = AuthTypeSASLNone;
}

NetService::NetService()
{
    init();
}

NetService::NetService(NetService * other)
{
    init();
    MC_SAFE_REPLACE_COPY(String, mHostname, other->mHostname);
    mPort = other->mPort;
    mConnectionType = other->mConnectionType;
    mSuggestedAuthType = other->mSuggestedAuthType;
}

NetService::~NetService()
{
    MC_SAFE_RELEASE(mHostname);
}

NetService * NetService::serviceWithInfo(HashMap * info)
{
    NetService * service = new NetService();
    service->fillWithInfo(info);
    service->autorelease();
    return service;
}

void NetService::fillWithInfo(HashMap * info)
{
    bool ssl = false;
    bool starttls = false;
    
    	
    setHostname((String *) info->objectForKey(MCSTR("hostname")));
    if (info->objectForKey(MCSTR("port")) != NULL) {
        setPort(((Value *) info->objectForKey(MCSTR("port")))->intValue());
    }
    if (info->objectForKey(MCSTR("ssl")) != NULL) {
        ssl = ((Value *) info->objectForKey(MCSTR("ssl")))->boolValue();
    }
    if (info->objectForKey(MCSTR("starttls")) != NULL) {
        starttls = ((Value *) info->objectForKey(MCSTR("starttls")))->boolValue();
    }
    
    if (info->objectForKey(MCSTR("suggested_auth_type")) != NULL) {
        String *authStr;
        authStr = ((String *) info->objectForKey(MCSTR("suggested_auth_type")));
        
        if (authStr->isEqualCaseInsensitive(MCSTR("none"))) {
            mSuggestedAuthType = AuthTypeSASLNone;
        } if (authStr->isEqualCaseInsensitive(MCSTR("crammd5"))) {
            mSuggestedAuthType = AuthTypeSASLCRAMMD5;
        } else if (authStr->isEqualCaseInsensitive(MCSTR("plain"))) {
            mSuggestedAuthType = AuthTypeSASLPlain;
        } else if (authStr->isEqualCaseInsensitive(MCSTR("gssapi"))) {
            mSuggestedAuthType = AuthTypeSASLGSSAPI;
        } else if (authStr->isEqualCaseInsensitive(MCSTR("digestmd5"))) {
            mSuggestedAuthType = AuthTypeSASLDIGESTMD5;
        } else if (authStr->isEqualCaseInsensitive(MCSTR("login"))) {
            mSuggestedAuthType = AuthTypeSASLLogin;
        } else if (authStr->isEqualCaseInsensitive(MCSTR("srp"))) {
            mSuggestedAuthType = AuthTypeSASLSRP;
        } else if (authStr->isEqualCaseInsensitive(MCSTR("ntlm"))) {
            mSuggestedAuthType = AuthTypeSASLNTLM;
        } else if (authStr->isEqualCaseInsensitive(MCSTR("kerberosv4"))) {
            mSuggestedAuthType = AuthTypeSASLKerberosV4;
        } else if (authStr->isEqualCaseInsensitive(MCSTR("oauth2"))) {
            mSuggestedAuthType = AuthTypeXOAuth2;
        } else if (authStr->isEqualCaseInsensitive(MCSTR("oauth2outlook"))) {
            mSuggestedAuthType = AuthTypeXOAuth2Outlook;
        }
    }
    
    if (ssl) {
        mConnectionType = ConnectionTypeTLS;
    }
    else if (starttls) {
        mConnectionType = ConnectionTypeStartTLS;
    }
    else {
        mConnectionType = ConnectionTypeClear;
    }
}

void NetService::setHostname(String *hostname)
{
    MC_SAFE_REPLACE_COPY(String, mHostname, hostname);
}

String * NetService::hostname()
{
    return mHostname;
}

void NetService::setPort(unsigned int port)
{
    mPort = port;
}

unsigned int NetService::port()
{
    return mPort;
}

void NetService::setConnectionType(ConnectionType connectionType)
{
    mConnectionType = connectionType;
}

ConnectionType NetService::connectionType()
{
    return mConnectionType;
}

void NetService::setSuggestedAuthType(AuthType authType)
{
    mSuggestedAuthType = authType;
}

AuthType NetService::suggestedAuthType()
{
    return mSuggestedAuthType;
}

String * NetService::normalizedHostnameWithEmail(String * email)
{
    Array *components = email->componentsSeparatedByString(MCSTR("@"));
    String *hostname = (String *) mHostname->copy()->autorelease();
    if (components->count() != 0) {
        hostname->replaceOccurrencesOfString(MCSTR("{domain}"), (String *) components->lastObject());
        return hostname;
    }
    return mHostname;
}

HashMap * NetService::info()
{
    HashMap * result;
    
    result = new HashMap();
    if (mHostname != NULL) {
        result->setObjectForKey(MCSTR("hostname"), mHostname);
    }
    if (mPort != 0) {
        result->setObjectForKey(MCSTR("port"), Value::valueWithIntValue(mPort));
    }
    
    switch (mConnectionType) {
        case ConnectionTypeTLS:
            result->setObjectForKey(MCSTR("ssl"), Value::valueWithBoolValue(true));
            break;
        case ConnectionTypeStartTLS:
            result->setObjectForKey(MCSTR("starttls"), Value::valueWithBoolValue(true));
            break;
        default:
            break;
    }
    
    String *key = MCSTR("suggested_auth_type");
    switch (mSuggestedAuthType) {
        case AuthTypeSASLCRAMMD5:
            result->setObjectForKey(key, MCSTR("crammd5"));
            break;
        case AuthTypeSASLPlain:
            result->setObjectForKey(key, MCSTR("plain"));
            break;
        case AuthTypeSASLGSSAPI:
            result->setObjectForKey(key, MCSTR("gssapi"));
            break;
        case AuthTypeSASLDIGESTMD5:
            result->setObjectForKey(key, MCSTR("digestmd5"));
            break;
        case AuthTypeSASLLogin:
            result->setObjectForKey(key, MCSTR("login"));
            break;
        case AuthTypeSASLSRP:
            result->setObjectForKey(key, MCSTR("srp"));
            break;
        case AuthTypeSASLNTLM:
            result->setObjectForKey(key, MCSTR("ntlm"));
            break;
        case AuthTypeSASLKerberosV4:
            result->setObjectForKey(key, MCSTR("kerberosv4"));
            break;
        case AuthTypeXOAuth2:
            result->setObjectForKey(key, MCSTR("oauth2"));
            break;
        case AuthTypeXOAuth2Outlook:
            result->setObjectForKey(key, MCSTR("oauth2outlook"));
            break;
        default:
            result->setObjectForKey(key, MCSTR("none"));
            break;
    }
    
    return result;
}

String * NetService::description()
{
    return String::stringWithUTF8Format("<%s:%p, hostname: %s, port: %u>", className()->UTF8Characters(), this, MCUTF8(mHostname), mPort);
}

Object * NetService::copy()
{
    return new NetService(this);
}
