/**
 * \file future_error_domain.h
 * \author Vincent WANG (you@domain.com)
 * \brief 
 * \version 0.1
 * \date 2020-12-04
 * 
 * \copyright Copyright (c) 2020
 * 
 */
#ifndef ARA_CORE_FUTURE_ERROR_DOMAIN_H_
#define ARA_CORE_FUTURE_ERROR_DOMAIN_H_

#include <cstdint>

namespace ara
{
    namespace core
    {
        // SWS_CORE_00400
        /**
         * \brief Specifies the types of internal errors that can occur upon calling Future::get or Future::Get
         * Result.
         * These definitions are equivalent to the ones from std::future_errc.
         * 
         */
        enum class future_errc : int32_t
        {
            broken_promis = 101,            /*< the asynchronous task abandoned its shared state */
            future_already_retrieved = 102, /*< the contents of the shared state were already
                                                accessed */
            promise_already_satisfied = 103,/*< attempt to store a value into the shared state twice */
            no_state = 104,                 /*< attempt to access Promise or Future without an
                                                associated state */
        };

        // SWS_CORE_00411
        /**
         * \brief Exception type thrown by Future and Promise classes.
         * 
         */
        class FutureException : public Exception
        {
            // SWS_CORE_00412
            /**
             * \brief Construct a new FutureException from an ErrorCode.
             * 
             * \param[in] err   the ErrorCode
             */
            explicit FutureException(ErrorCode err) noexcept;
        };

        // SWS_CORE_00421
        /**
         * \brief Error domain for errors originating from classes Future and Promise. .
         * 
         * Unique ID 0x8000’0000’0000’0013
         */
        class FutureErrorDomain final : public ErrorDomain
        {
            // SWS_CORE_00431
            /**
             * \brief Alias for the error code value enumeration.
             * 
             */
            using Errc = future_errc;

            // SWS_CORE_00432
            /**
             * \brief Alias for the exception base class.
             * 
             */
            using Exception = FutureException;

            // SWS_CORE_00441
            /**
             * \brief Default constructor.
             * 
             */
            constexpr FutureErrorDomain() noexcept;

            // SWS_CORE_00442
            /**
             * \brief Return the "shortname" ApApplicationErrorDomain.SN of this error domain.
             * 
             * \return char const*  "Future"
             */
            char const* Name() const noexcept override;

            // SWS_CORE_00443
            /**
             * \brief Translate an error code value into a text message.
             * 
             * \param[in] errorCode     the error code value
             * \return char const*      the text message, never nullptr
             */
            char const* Message(FutureErrorDomain::CodeType errorCode) const noexcept;

            // SWS_CORE_00444
            /**
             * \brief Throw the exception type corresponding to the given ErrorCode.
             * 
             * \param[in] errorCode     the ErrorCode instance
             */
            void ThrowAsException(ErrorCode const &errorCode) const noexcept(false) override;
        };

        // SWS_CORE_00480
        /**
         * \brief Obtain the reference to the single global FutureErrorDomain instance.
         * 
         * \return ErrorDomain const&     reference to the FutureErrorDomain instance
         */
        constexpr ErrorDomain const& GetFutureErrorDomain() noexcept;

        // SWS_CORE_00490
        /**
         * \brief Create a new ErrorCode for FutureErrorDomain with the given support data type.
         * 
         * \param[in] code  an enumeration value from future_errc 
         * \param[in] data  a vendor-defined supplementary value
         * 
         * \return ErrorCode  the new ErrorCode instance
         */
        constexpr ErrorCode MakeErrorCode(future_errc code, ErrorDomain::SupportDataType data) noexcept;
    } // namespace core
    
} // namespace ara


#endif // ARA_CORE_FUTURE_ERROR_DOMAIN_H_
