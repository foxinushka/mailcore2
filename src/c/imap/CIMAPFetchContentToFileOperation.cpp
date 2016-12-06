#include "CIMAPFetchContentToFileOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPFetchContentToFileOperation
#define structName CIMAPFetchContentToFileOperation

bool isLoadingByChunksEnabled(struct CIMAPFetchContentToFileOperation self) {
    return self.instance->isLoadingByChunksEnabled();
}

uint32_t chunksSize(struct CIMAPFetchContentToFileOperation self) {
    return self.instance->chunksSize();
}

uint32_t estimatedSize(struct CIMAPFetchContentToFileOperation self) {
    return self.instance->estimatedSize();
}

void setLoadingByChunksEnabled(struct CIMAPFetchContentToFileOperation self, bool newValue) {
    self.instance->setLoadingByChunksEnabled(newValue);
}

void setChunksSize(struct CIMAPFetchContentToFileOperation self, uint32_t newValue) {
    self.instance->setChunksSize(newValue);
}

void setEstimatedSize(struct CIMAPFetchContentToFileOperation self, uint32_t newValue) {
    self.instance->setEstimatedSize(newValue);
}

CIMAPFetchContentToFileOperation newCIMAPFetchContentToFileOperation(mailcore::IMAPFetchContentToFileOperation *operationRef){
    CIMAPFetchContentToFileOperation self;
    self.baseOperation = newCIMAPBaseOperation(operationRef);
    self.instance = operationRef;
    
    self.isLoadingByChunksEnabled = &isLoadingByChunksEnabled;
    self.chunksSize = &chunksSize;
    self.estimatedSize = &estimatedSize;
    self.setLoadingByChunksEnabled = &setLoadingByChunksEnabled;
    self.setChunksSize = &setChunksSize;
    self.setEstimatedSize = &setEstimatedSize;
    
    return self;
}

void deleteCIMAPFetchContentToFileOperation(CIMAPFetchContentToFileOperation operation) {
    
}
