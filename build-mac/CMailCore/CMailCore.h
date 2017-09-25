//
//  CMailCore.h
//  CMailCore framework
//
//  Copyright (c) 2015 Readdle. All rights reserved.
//

// Fake module
// TODO: move CMailCore to indiivdual module

#include <libetpan/libetpan.h>

extern int mailimap_hack_date_time_parse(char * str,
                                             struct mailimap_date_time ** result,
                                             size_t progr_rate,
                                             progress_function * progr_fun);

extern time_t MailCoreTimestampFromDate(struct mailimf_date_time * date_time);
extern time_t MailCoreTimestampFromIMAPDate(struct mailimap_date_time * imap_date);
