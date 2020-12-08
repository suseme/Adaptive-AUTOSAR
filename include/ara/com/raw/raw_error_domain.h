/**
 * \file raw_error_domain.h
 * \author Vincent WANG (you@domain.com)
 * \brief 
 * \version 0.1
 * \date 2020-12-08
 * 
 * \copyright Copyright (c) 2020
 * 
 */
#ifndef ARA_COM_RAW_RAW_ERROR_DOMAIN_H_
#define ARA_COM_RAW_RAW_ERROR_DOMAIN_H_

namespace ara
{
    namespace com
    {
        namespace raw
        {
            // SWS_CM_12367
            /**
             * \brief The @ARTechTerm{RawErrc} enumeration defines the error codes for the RawErrorDomain.
             * 
             */
            enum class RawErrc : ara::core::ErrorDomain::CodeType
            {
                kStreamNotConnected = 1,    /*< Trying to use a raw data stream without an
                                                established connection. */
                kCommunicationTimeout = 2,  /*< The operation was not successful and timed out. */
                kConnectionRefused = 3,     /*< The target address was not listening for connections
                                                or refused the connection request. */
                kAddressNotAvailable = 4,   /*< The specified address is not available from the local
                                                machine. */
                kStreamAlreadyConnected = 5,/*< The specified connection is already connected. */
            };
        } // namespace raw
        
    } // namespace com
    
} // namespace ara


#endif // ARA_COM_RAW_RAW_ERROR_DOMAIN_H_
