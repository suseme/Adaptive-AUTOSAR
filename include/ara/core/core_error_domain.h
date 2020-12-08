/**
 * \file core_error_domain.h
 * \author Vincent WANG (you@domain.com)
 * \brief 
 * \version 0.1
 * \date 2020-12-04
 * 
 * \copyright Copyright (c) 2020
 * 
 */
#ifndef ARA_CORE_CORE_ERROR_DOMAIN_H_
#define ARA_CORE_CORE_ERROR_DOMAIN_H_

#include "error_domain.h"
#include "error_code.h"

namespace ara
{
    namespace core
    {
        // SWS_CORE_05200
        /**
         * \brief An enumeration that defines all errors of the CORE Functional Cluster.
         * 
         */
        enum class CoreErrc : ErrorDomain::CodeType
        {
            kInvalidArgument = 22,              /*< an invalid argument was passed to a function */
            kInvalidMetaModelShortname = 137,   /*< given string is not a valid model element shortname */
            kInvalidMetaModelPath = 138,        /*< missing or invalid path to model element */
        };

        // SWS_CORE_05211
        /**
         * \brief Exception type thrown for CORE errors.
         * 
         */
        class CoreException : public Exception
        {
            // SWS_CORE_05212
            /**
             * \brief Construct a new CoreException from an ErrorCode.
             * 
             * \param[in] err   the ErrorCode
             */
            explicit CoreException(ErrorCode err) noexcept;
        };

        // SWS_CORE_05221
        /**
         * \brief An error domain for errors originating from the CORE Functional Cluster 
         * 
         * \Unique ID   0x8000’0000’0000’0014
         */
        class CoreErrorDomain final : public ErrorDomain
        {
            // SWS_CORE_05231
            /**
             * \brief Alias for the error code value enumeration.
             * 
             */
            using Errc = CoreErrc;

            // SWS_CORE_05232
            /**
             * \brief Alias for the exception base class.
             * 
             */
            using Exception = CoreException;

            // SWS_CORE_05241
            /**
             * \brief Default constructor.
             * 
             */
            constexpr CoreErrorDomain() noexcept;

            // SWS_CORE_05242
            /**
             * \brief Return the "shortname" ApApplicationErrorDomain.SN of this error domain.
             * 
             * \return char const*  Core
             */
            char const* Name() const noexcept override;

            // SWS_CORE_05243
            /**
             * \brief Translate an error code value into a text message.
             * 
             * \param[in] errorCode     the error code value
             * \return char const*      the text message, never nullptr
             */
            char const* Message(ErrorDomain::CodeType errorCode) const noexcept override;

            // SWS_CORE_05244
            /**
             * \brief Throw the exception type corresponding to the given ErrorCode.
             * 
             * \param[in] errorCode     the ErrorCode instance
             */
            void ThrowAsException(ErrorCode const &errorCode) const override;
        };

        // SWS_CORE_05280
        /**
         * \brief Return a reference to the global CoreErrorDomain.
         * 
         * \return constexpr ErrorDomain const&     the CoreErrorDomain
         */
        constexpr ErrorDomain const& GetCoreErrorDomain() noexcept;

        // SWS_CORE_05290
        /**
         * \brief Create a new ErrorCode within CoreErrorDomain.
         * This function is used internally by constructors of ErrorCode. It is usually not used directly by
         * users.
         * 
         * \param[in] code  the CoreErrorDomain-specific error code value 
         * \param[in] data  optional vendor-specific error data
         * 
         * \return constexpr ErrorCode 
         */
        constexpr ErrorCode MakeErrorCode(CoreErrc code, ErrorDomain::SupportDataType data) noexcept;

    } // namespace core
    
} // namespace ara


#endif // ARA_CORE_CORE_ERROR_DOMAIN_H_
