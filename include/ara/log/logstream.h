/**
 * \file logstream.h
 * \author Vincent WANG (you@domain.com)
 * \brief 
 * \version 0.1
 * \date 2020-12-08
 * 
 * \copyright Copyright (c) 2020
 * 
 */
#ifndef ARA_LOG_LOGSTREAM_H_
#define ARA_LOG_LOGSTREAM_H_

#include <cstdint>
#include "ara/core/error_code.h"

namespace ara
{
    namespace log
    {
        // SWS_LOG_00108
        /**
         * \brief Represents a 8 bit hexadecimal value data type .
         * 
         * Helper struct that is utilized as custom type. Holds an integer value that will be logged with a
         * special format.
         * 
         */
        struct LogHex8
        {
            /* data */
        };

        // SWS_LOG_00109
        /**
         * \brief Represents a 16 bit hexadecimal value data type .
         * 
         */
        struct LogHex16
        {
            /* data */
        };
        
        // SWS_LOG_00110
        /**
         * \brief Represents a 32 bit hexadecimal value data type .
         * 
         */
        struct LogHex32
        {
            /* data */
        };

        // SWS_LOG_00111
        /**
         * \brief Represents a 64 bit hexadecimal value data type .
         * 
         */
        struct LogHex64
        {
            /* data */
        };

        // SWS_LOG_00112
        /**
         * \brief Represents a 8 bit binary data type .
         * 
         */
        struct LogBin8
        {
            /* data */
        };

        // SWS_LOG_00113
        /**
         * \brief Represents a 16 bit binary data type .
         * 
         */
        struct LogBin16
        {
            /* data */
        };

        // SWS_LOG_00114
        /**
         * \brief Represents a 32 bit binary data type .
         * 
         */
        struct LogBin32
        {
            /* data */
        };

        // SWS_LOG_00115
        /**
         * \brief Represents a 64 bit binary data type .
         * 
         */
        struct LogBin64
        {
            /* data */
        };

        // SWS_LOG_00116
        /**
         * \brief Represents a raw data buffer of a limited size.
         * 
         * Helper struct that is utilized as custom type. Holds a pointer to some data and the size which is
         * to be logged as raw data.
         * 
         */
        struct LogRawBuffer
        {
            /* data */
        };

        class LogStream
        {
            // SWS_LOG_00039
            /**
             * \brief Sends out the current log buffer and initiates a new message stream.
             * 
             * \note 
             * \thread safety reentrant
             */
            void Flush() noexcept;

            // SWS_LOG_00040
            /**
             * \brief Appends given value to the internal message buffer.
             * 
             * \param[in] value     Value to be appended to the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(bool value) noexcept;

            // SWS_LOG_00041
            /**
             * \brief 
             * 
             * \param[in|out] value 
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(uint8_t value) noexcept;

            // SWS_LOG_00042
            /**
             * \brief Writes unsigned int 16 bit parameter into message.
             * 
             * \param[in] value     Value to be appended to the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(uint16_t value) noexcept;

            // SWS_LOG_00043
            /**
             * \brief Writes unsigned int 32 bit parameter into message.
             * 
             * \param[in] value     Value to be appended to the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(uint32_t value) noexcept;

            // SWS_LOG_00044
            /**
             * \brief Writes unsigned int 64 bit parameter into message.
             * 
             * \param[in] value     Value to be appended to the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(uint64_t value) noexcept;

            // SWS_LOG_00045
            /**
             * \brief Writes signed int 8 bit parameter into message.
             * 
             * \param[in] value     Value to be appended to the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(int8_t value) noexcept;

            // SWS_LOG_00046
            /**
             * \brief Writes signed int 16 bit parameter into message.
             * 
             * \param[in] value     Value to be appended to the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(int16_t value) noexcept;

            // SWS_LOG_00047
            /**
             * \brief Writes signed int 32 bit parameter into message.
             * 
             * \param[in] value     Value to be appended to the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(int32_t value) noexcept;

            // SWS_LOG_00048
            /**
             * \brief Writes signed int 64 bit parameter into message.
             * 
             * \param[in] value     Value to be appended to the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(int64_t value) noexcept;

            // SWS_LOG_00049
            /**
             * \brief Writes float 32 bit parameter into message.
             * 
             * \param[in] value     Value to be appended to the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(float value) noexcept;

            // SWS_LOG_00050
            /**
             * \brief Writes float 64 bit parameter into message.
             * 
             * \param[in] value     Value to be appended to the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(double value) noexcept;

            // SWS_LOG_00061
            /**
             * \brief Writes plain binary data into message.
             * 
             * \param[in] value     Value to be appended to the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(const LogRawBuffer &value) noexcept;

            // SWS_LOG_00053
            /**
             * \brief Writes unsigned int parameter into message, formatted as hexadecimal 8 digits.
             * 
             * \param[in] value     Value to be appended to the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(const LogHex8 &value) noexcept;

            // SWS_LOG_00054
            /**
             * \brief Writes unsigned int parameter into message, formatted as hexadecimal 16 digits.
             * 
             * \param[in] value     Value to be appended to the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(const LogHex16 &value) noexcept;

            // SWS_LOG_00055
            /**
             * \brief Writes unsigned int parameter into message, formatted as hexadecimal 32 digits.
             * 
             * \param[in] value     Value to be appended to the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(const LogHex32 &value) noexcept;

            // SWS_LOG_00056
            /**
             * \brief Writes unsigned int parameter into message, formatted as hexadecimal 64 digits.
             * 
             * \param[in] value     Value to be appended to the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(const LogHex64 &value) noexcept;

            // SWS_LOG_00057
            /**
             * \brief Writes unsigned int parameter into message, formatted as binary 8 digits.
             * 
             * \param[in] value     Value to be appended to the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(const LogBin8 &value) noexcept;

            // SWS_LOG_00058
            /**
             * \brief Writes unsigned int parameter into message, formatted as binary 16 digits.
             * 
             * \param[in] value     Value to be appended to the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(const LogBin16 &value) noexcept;

            // SWS_LOG_00059
            /**
             * \brief Writes unsigned int parameter into message, formatted as binary 32 digits.
             * 
             * \param[in] value     Value to be appended to the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(const LogBin32 &value) noexcept;

            // SWS_LOG_00060
            /**
             * \brief Writes unsigned int parameter into message, formatted as binary 64 digits.
             * 
             * \param[in] value     Value to be appended to the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(const LogBin64 &value) noexcept;

            // SWS_LOG_00062
            /**
             * \brief Writes ara::core::StringView into message.
             * 
             * \param[in] value     Value to be appended to the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(const ara::core::StringView &value) noexcept;

            // SWS_LOG_00051
            /**
             * \brief Writes null terminated UTF8 string into message. (NOT sPECIFIED. WILL BE REMOVED IN FUTURE!)
             * 
             * \param[in] value     Value to be appended to the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(const char *const value) noexcept;

            // SWS_LOG_00063
            /**
             * \brief Appends LogLevel enum parameter as text into message.
             * 
             * \param[in] out 
             * \param[in] value     LogLevel enum parameter as text to be appended to
             *                      the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(LogStream &out, LogLevel value) noexcept;

            // SWS_LOG_00124
            /**
             * \brief Writes an ara::core::ErrorCode into the message, containing a String holding the results of
             *  ErrorCode:Domain().Name() (i.e. the ErrorDomain’s Shortname), and the integral error code
             *  number.
             * 
             * \param[in] value     Value to be appended to the internal message buffer.
             * \return LogStream& 
             * \note 
             * \thread safety reentrant
             */
            LogStream& operator<<(const ara::core::ErrorCode &value) noexcept;
        };
    } // namespace log
    
} // namespace ara


#endif // ARA_LOG_LOGSTREAM_H_
