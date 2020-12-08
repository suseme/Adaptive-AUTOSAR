/**
 * \file common.h
 * \author Vincent WANG (you@domain.com)
 * \brief 
 * \version 0.1
 * \date 2020-12-08
 * 
 * \copyright Copyright (c) 2020
 * 
 */
#ifndef ARA_LOG_COMMON_H_
#define ARA_LOG_COMMON_H_

#include <cstddef>

namespace ara
{
    namespace log
    {
        // SWS_LOG_00018
        /**
         * \brief List of possible severity levels .
         * 
         */
        enum class LogLevel : uint8_t
        {
            kOff = 0x00,    /*< No logging. */
            kFatal = 0x01,  /*< Fatal error, not recoverable. */
            kError = 0x02,  /*< Error with impact to correct functionality. */
            kWarn = 0x03,   /*< Warning if correct behavior cannot be ensured. */
            kInfo = 0x04,   /*< Informational, providing high level understanding. */
            kDebug = 0x05,  /*< Detailed information for programmers. */
            kVerbose = 0x06,/*< Extra-verbose debug messages (highest grade of
                                information) */
        };

        // 
        /**
         * \brief Log mode. Flags, used to configure the sink for log messages.
         * 
         * \note In order to combine flags, at least the OR and AND operators needs to be provided for this type.
         */
        enum class LogMode : uint8_t
        {
            kRemote = 0x01, /*< Sent remotely. */
            kFile = 0x02,   /*< Save to file. */
            kConsole = 0x04,/*< Forward to console. */
        };

        // SWS_LOG_00098
        /**
         * \brief Client state representing the connection state of an external client. .
         * 
         */
        enum class ClientState : int8_t
        {
            kUnknown = -1,
            kNotConnected,
            kConnected,
        };
    } // namespace log
    
} // namespace ara


#endif // ARA_LOG_COMMON_H_
