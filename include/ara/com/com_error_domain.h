/**
 * \file com_error_domain.h
 * \author Vincent WANG (you@domain.com)
 * \brief 
 * \version 0.1
 * \date 2020-12-08
 * 
 * \copyright Copyright (c) 2020
 * 
 */
#ifndef ARA_COM_COM_ERROR_DOMAIN_H_
#define ARA_COM_COM_ERROR_DOMAIN_H_

#include "ara/core/error_domain.h"

namespace ara
{
    namespace com
    {
        // SWS_CM_10432
        /**
         * \brief The @ARTechTerm{ComErrc} enumeration defines the error codes for the ComErrorDomain.
         * 
         */
        enum class ComErrc : ara::core::ErrorDomain::CodeType
        {
            kServiceNotAvailable = 1,   /*< Service is not available. */
            kMaxSamplesExceeded = 2,    /*< Application holds more SamplePtrs than commited
                                            in Subscribe().*/
            kNetworkBindingFailure = 3, /*< Local failure has been detected by the network
                                            binding. */
        };
    } // namespace com
    
} // namespace ara// 


#endif // ARA_COM_COM_ERROR_DOMAIN_H_
