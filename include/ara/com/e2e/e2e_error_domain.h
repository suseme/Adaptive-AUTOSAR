/**
 * \file e2e_error_domain.h
 * \author Vincent WANG (you@domain.com)
 * \brief 
 * \version 0.1
 * \date 2020-12-08
 * 
 * \copyright Copyright (c) 2020
 * 
 */
#ifndef ARA_COM_E2E_E2E_ERROR_DOMAIN_H_
#define ARA_COM_E2E_E2E_ERROR_DOMAIN_H_

#include "ara/core/error_domain.h"

namespace ara
{
    namespace com
    {
        namespace e2e
        {
            // SWS_CM_10474
            /**
             * \brief The @ARTechTerm{E2EError} enumeration defines the error codes for the E2EErrorDomain. .
             * 
             */
            enum class E2EError : ara::core::ErrorDomain::CodeType
            {
                repreated = 1,              /*< Data has a repeated counter. */
                wrong_sequence_error = 2,   /*< The checks of the Data in this cycle were
                                                successful, with the exception of counter jump,
                                                which changed more than the allowed delta. Error
                                                not related to counters occurred (e.g. wrong crc,
                                                wrong length, wrong Data ID) or the return of the
                                                check function was not OK. */
                error = 3,                  /*< see above */
                not_available = 4,          /*< No value has been received yet (e.g. during
                                                initialization). This is used as the initialization value
                                                for the buffer, it is not returned by any E2E profile. */
                no_new_data = 5,            /*< No new data is available. */
            };
        } // namespace e2e
        
    } // namespace com
    
} // namespace ara


#endif // ARA_COM_E2E_E2E_ERROR_DOMAIN_H_
