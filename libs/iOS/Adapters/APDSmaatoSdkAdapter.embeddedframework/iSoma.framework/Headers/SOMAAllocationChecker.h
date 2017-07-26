//
//  SOMAAllocationChecker.h
//  iSoma
//
//  Created by Aman Shaikh on 27/01/2017.
//  Copyright © 2017 Smaato Inc. All rights reserved.
//

//#define SOMA_ENABLE_ALLOCATION_TRACE 1

#ifndef SOMAAllocationChecker_h
#define SOMAAllocationChecker_h

#ifdef SOMA_ENABLE_ALLOCATION_TRACE

#define SOMA_TRACE_ALLOC _soma_increment_allocation(NSStringFromClass(self.class));
#define SOMA_TRACE_DEALLOC _soma_decrement_allocation(NSStringFromClass(self.class));

#define SOMA_TRACE_STAT _soma_print_allocation_stat();
#define SOMA_TRACE_RESET_ALL _soma_reset_allocation_stat();

void _soma_increment_allocation(NSString* className);
void _soma_decrement_allocation(NSString* className);
void _soma_print_allocation_stat();
void _soma_reset_allocation_stat();
#else

#define SOMA_TRACE_ALLOC
#define SOMA_TRACE_DEALLOC
#define SOMA_TRACE_STAT
#define SOMA_TRACE_RESET_ALL
#endif

#endif /* SOMAAllocationChecker_1_h */
