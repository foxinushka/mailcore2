#include "CIMAPFetchContentToFileOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPFetchContentToFileOperation
#define structName CIMAPFetchContentToFileOperation

bool CIMAPFetchContentToFileOperation_isLoadingByChunksEnabled(struct CIMAPFetchContentToFileOperation self) {
    return self.instance->isLoadingByChunksEnabled();
}

uint32_t CIMAPFetchContentToFileOperation_chunksSize(struct CIMAPFetchContentToFileOperation self) {
    return self.instance->chunksSize();
}

uint32_t CIMAPFetchContentToFileOperation_estimatedSize(struct CIMAPFetchContentToFileOperation self) {
    return self.instance->estimatedSize();
}

void CIMAPFetchContentToFileOperation_setLoadingByChunksEnabled(struct CIMAPFetchContentToFileOperation self, bool newValue) {
    self.instance->setLoadingByChunksEnabled(newValue);
}

void CIMAPFetchContentToFileOperation_setChunksSize(struct CIMAPFetchContentToFileOperation self, uint32_t newValue) {
    self.instance->setChunksSize(newValue);
}

void CIMAPFetchContentToFileOperation_setEstimatedSize(struct CIMAPFetchContentToFileOperation self, uint32_t newValue) {
    self.instance->setEstimatedSize(newValue);
}

CIMAPFetchContentToFileOperation CIMAPFetchContentToFileOperation_new(mailcore::IMAPFetchContentToFileOperation *operationRef){
    CIMAPFetchContentToFileOperation self;
    self.baseOperation = CIMAPBaseOperation_new(operationRef);
    self.instance = operationRef;
    return self;
}

void CIMAPFetchContentToFileOperation_release(CIMAPFetchContentToFileOperation operation) {
    
}
