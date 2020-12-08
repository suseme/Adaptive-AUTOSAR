/**
 * \file logging.h
 * \author Vincent WANG (you@domain.com)
 * \brief 
 * \version 0.1
 * \date 2020-12-08
 * 
 * \copyright Copyright (c) 2020
 * 
 */
#ifndef ARA_LOG_LOGGING_H_
#define ARA_LOG_LOGGING_H_

#include "ara/core/"

namespace ara
{
    namespace log
    {
        // SWS_LOG_00021
        /**
         * \brief Creates a Logger object, holding the context which is registered in the Logging framework.
         * 
         * \param[in] ctxId     The context ID.
         * \param[in] ctxDescription    The description of the provided context ID.
         * \param[in] ctxDefLogLevel    The default log level, set to Warning severity if not
         *                              explicitly specified.
         * \return Logger&              Reference to the internal managed instance of a
         *                              Logger object. Ownership stays within the Logging
         *                              framework
         * \thread satety   reentrant
         */
        Logger& CreateLogger(ara::core::StringView ctxId, ara::core::StringView ctxDescription, LogLevel ctxDefLogLevel=LogLevel::kWarn) noexcept;

        // SWS_LOG_00022
        /**
         * \brief Conversion of a uint8 into a hexadecimal value.
         * 
         * Negatives are represented in 2’s complement. The number of represented digits depends on
         * the overloaded parameter type length.
         * 
         * \param[in] value     Decimal number to be converted into hexadecimal
         *                      number system.
         * \return LogHex8      LogHex8 type that has a built-in stream handler.
         * 
         * \note Logs decimal numbers in hexadecimal format.
         */
        constexpr LogHex8 HexFormat(uint8_t value) noexcept;

        // SWS_LOG_00023
        /**
         * \brief Conversion of a int8 into a hexadecimal value.
         * 
         * \param[in] value     Decimal number to be converted into hexadecimal
         *                      number system.
         * 
         * \return LogHex8      LogHex8 type that has a built-in stream handler.
         * 
         * \note Logs decimal numbers in hexadecimal format. Negatives are represented in 2’s complement.
         */
        constexpr LogHex8 HexFormat(int8_t value) noexcept;

        // SWS_LOG_00024
        /**
         * \brief Conversion of a uint16 into a hexadecimal value.
         * 
         * \param[in] value     Decimal number to be converted into hexadecimal
         *                      number system.
         * \return LogHex16     LogHex16 type that has a built-in stream handler.
         * 
         * \note Logs decimal numbers in hexadecimal format.
         */
        constexpr LogHex16 HexFormat(uint16_t value) noexcept;

        // SWS_LOG_00025
        /**
         * \brief Conversion of a int16 into a hexadecimal value.
         * 
         * \param[in] value     Decimal number to be converted into hexadecimal
         *                      number system.
         * \return LogHex16 
         * 
         * \note Logs decimal numbers in hexadecimal format. Negatives are represented in 2’s complement.
         * 
         * \thread safety   reentrant
         */
        constexpr LogHex16 HexFormat(int16_t value) noexcept;

        // SWS_LOG_00026
        /**
         * \brief Conversion of a uint32 into a hexadecimal value.
         * 
         * \param[in] value     Decimal number to be converted into hexadecimal
         *                      number system.
         * \return LogHex32     LogHex32 type that has a built-in stream handler.
         * 
         * \note Logs decimal numbers in hexadecimal format.
         */
        constexpr LogHex32 HexFormat(uint32_t value) noexcept;

        // SWS_LOG_00027
        /**
         * \brief Conversion of a int32 into a hexadecimal value.
         * 
         * \param[in] value     Decimal number to be converted into hexadecimal
         *                      number system.
         * \return LogHex32     LogHex32 type that has a built-in stream handler.
         * 
         * \note Logs decimal numbers in hexadecimal format. Negatives are represented in 2’s complement.
         * 
         * \thread safety reentrant
         */
        constexpr LogHex32 HexFormat(int32_t value) noexcept;

        // SWS_LOG_00028
        /**
         * \brief Conversion of a uint64 into a hexadecimal value.
         * 
         * \param[in] value     Decimal number to be converted into hexadecimal
         *                      number system.
         * \return LogHex64     LogHex64 type that has a built-in stream handler.
         * 
         * \note Logs decimal numbers in hexadecimal format.
         * 
         * \thread safety reentrant
         */
        constexpr LogHex64 HexFormat(uint64_t value) noexcept;

        // SWS_LOG_00029
        /**
         * \brief Conversion of a int64 into a hexadecimal value.
         * 
         * \param[in] value     Decimal number to be converted into hexadecimal
         *                      number system.
         * 
         * \return LogHex64     LogHex64 type that has a built-in stream handler.
         * 
         * \note Logs decimal numbers in hexadecimal format. Negatives are represented in 2’s complement.
         * 
         * \thread safety reentrant
         */
        constexpr LogHex64 HexFormat(int64_t value) noexcept;

        // SWS_LOG_00030
        /**
         * \brief Conversion of a uint8 into a binary value.
         * 
         * \note Logs decimal numbers in binary format.
         * 
         * \thread safety reentrant
         * 
         * \param[in] value     Decimal number to be converted into a binary value.
         * 
         * \return LogBin8      LogBin8 type that has a built-in stream handler.
         */
        constexpr LogBin8 BinFormat(uint8_t value) noexcept;

        // SWS_LOG_00031
        /**
         * \brief Conversion of a int8 into a binary value.
         * 
         * \note Logs decimal numbers in binary format. Negatives are represented in 2’s complement.
         * 
         * \thread safety reentrant
         * 
         * \param[in] value     Decimal number to be converted into a binary value.
         * 
         * \return LogBin8      LogBin8 type that has a built-in stream handler.
         */
        constexpr LogBin8 BinFormat(int8_t value) noexcept;

        // SWS_LOG_00032
        /**
         * \brief Conversion of a uint16 into a binary value.
         * 
         * \param[in] value     Decimal number to be converted into a binary value.
         * \return LogBin16     Return value: LogBin16 
         * \note Logs decimal numbers in binary format.
         * \thread safety reentrant
         */
        constexpr LogBin16 BinFormat(uint16_t value) noexcept;

        // SWS_LOG_00033
        /**
         * \brief Conversion of a int16 into a binary value.
         * 
         * \param[in] value     Decimal number to be converted into a binary value.
         * \return LogBin16     LogBin32 type that has a built-in stream handler.
         * \note Logs decimal numbers in binary format. Negatives are represented in 2’s complement.
         * \thread safety reentrant
         */
        constexpr LogBin16 BinFormat(int16_t value) noexcept;

        // SWS_LOG_00034
        /**
         * \brief Conversion of a uint32 into a binary value.
         * 
         * \param[in] value     Decimal number to be converted into a binary value.
         * \return LogBin32     LogBin32 type that has a built-in stream handler.
         * \note Logs decimal numbers in binary format.
         * \thread safety reentrant
         */
        constexpr LogBin32 BinFormat(uint32_t value) noexcept;

        // SWS_LOG_00035
        /**
         * \brief Conversion of a int32 into a binary value.
         * 
         * \param[in] value     Decimal number to be converted into a binary value.
         * \return LogBin32     LogBin32 type that has a built-in stream handler.
         * \note Logs decimal numbers in binary format. Negatives are represented in 2’s complement.
         * \thread safety reentrant
         */
        constexpr LogBin32 BinFormat(int32_t value) noexcept;

        // SWS_LOG_00036
        /**
         * \brief Conversion of a uint64 into a binary value.
         * 
         * \param[in] value     Decimal number to be converted into a binary value.
         * \return LogBin64     LogBin64 type that has a built-in stream handler.
         * \note Logs decimal numbers in binary format.
         * \thread safety reentrant
         */
        constexpr LogBin64 BinFormat(uint64_t value) noexcept;

        // SWS_LOG_00037
        /**
         * \brief Conversion of a int64 into a binary value.
         * 
         * \param[in] value     Decimal number to be converted into a binary value.
         * \return LogBin64     LogBin64 type that has a built-in stream handler.
         * \note Logs decimal numbers in binary format. Negatives are represented in 2’s complement.
         * \thread safety reentrant
         */
        constexpr LogBin64 BinFormat(int64_t value) noexcept;

        // SWS_LOG_00038
        /**
         * \brief Logs raw binary data by providing a buffer.
         * 
         * \tparam T    The type of the contents of value.
         * \tparam std::enable_if<!std::is_pointer<T>::value, std::nullptr_t>::type 
         * \param[in] value     the value to convert to raw data.
         * \return LogRawBuffer LogRawBuffer type that has a built-in stream handler.
         * \note T can take an arbitrary type, though it is not possible to specify a pointer as an argument. The
         *       maximum size of the provided data that can be processed depends on the underlying back-end
         *       implementation.
         * \thread safety reentrant
         */
        template<typename T, typename std::enable_if<!std::is_pointer<T>::value, std::nullptr_t>::type = nullptr>
        constexpr LogRawBuffer RawBuffer(const T &value) noexcept;

        // SWS_LOG_00101
        /**
         * \brief Fetches the connection state from the DLT back-end of a possibly available remote client.
         * 
         * \return ClientState  The current client state.
         * \note 
         * \thread safety reentrant
         */
        ClientState remoteClientState() const noexcept;
    } // namespace log
    
} // namespace ara


#endif // ARA_LOG_LOGGING_H_
