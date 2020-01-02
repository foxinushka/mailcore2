//
//  MCLibetpan.h
//  mailcore2
//
//  Created by Hoa Dinh on 6/28/13.
//  Copyright (c) 2013 MailCore. All rights reserved.
//

#ifndef MAILCORE_MCLIBETPAN_H

#define MAILCORE_MCLIBETPAN_H

#include <time.h>
#include <libetpan/libetpan.h>
#include <MailCore/MCUtils.h>

#ifdef __cplusplus
namespace mailcore {

	MAILCORE_EXPORT time_t timestampFromDate(struct mailimf_date_time * date_time);
	MAILCORE_EXPORT time_t timestampFromIMAPDate(struct mailimap_date_time * date_time);
	MAILCORE_EXPORT struct mailimf_date_time * dateFromTimestamp(time_t timeval);
	MAILCORE_EXPORT struct mailimap_date_time * imapDateFromTimestamp(time_t timeval);
	MAILCORE_EXPORT time_t mkgmtime(struct tm * tmp);
    
}
#endif
#endif
