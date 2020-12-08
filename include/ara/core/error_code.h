/**
 * \file error_code.h
 * \author Vincent WANG (you@domain.com)
 * \brief 
 * \version 0.1
 * \date 2020-12-04
 * 
 * \copyright Copyright (c) 2020
 * 
 */
#ifndef ARA_CORE_ERROR_CODE_H_
#define ARA_CORE_ERROR_CODE_H_

#include "ara/core/error_domain.h"

namespace ara
{
    namespace core
    {
        // SWS_CORE_00501
        /**
         * \brief Encapsulation of an error code.
         * 
         * An ErrorCode contains a raw error code value and an error domain. The raw error code value is
         * specific to this error domain.
         * 
         */
        class ErrorCode final
        {
            // SWS_CORE_00512
            /**
             * \brief Construct a new ErrorCode instance with parameters.
             * 
             * This constructor does not participate in overload resolution unless EnumT is an enum type.
             * 
             * \tparam EnumT    an enum type that contains error code values
             * 
             * \param e     a domain-specific error code value
             * \param data  optional vendor-specific supplementary error context data
             */
            template <typename EnumT>
            constexpr ErrorCode(EnumT e, ErrorDomain::SupportDataType data=ErrorDomain::SupportDataType()) noexcept;

            // SWS_CORE_00513
            /**
             * \brief Construct a new ErrorCode instance with parameters.
             *
             * \param value     a domain-specific error code value
             * \param domain    the ErrorDomain associated with value
             * \param data      optional vendor-specific supplementary error context data
             */
            constexpr ErrorCode(ErrorDomain::CodeType value, ErrorDomain const &domain, ErrorDomain::SupportDataType data=ErrorDomain::SupportDataType()) noexcept;

            // SWS_CORE_00514
            /**
             * \brief Return the raw error code value.
             * 
             * \return constexpr ErrorDomain::CodeType  the raw error code value
             */
            constexpr ErrorDomain::CodeType Value() const noexcept;

            // SWS_CORE_00515
            /**
             * \brief Return the domain with which this ErrorCode is associated.
             * 
             * \return constexpr ErrorDomain const&     the ErrorDomain
             */
            constexpr ErrorDomain const& Domain() const noexcept;

            // SWS_CORE_00516
            /**
             * \brief Return the supplementary error context data.
             * 
             * The underlying type and the meaning of the returned value are implementation-defined.
             * 
             * \return constexpr ErrorDomain::SupportDataType   the supplementary error context data
             */
            constexpr ErrorDomain::SupportDataType SupportData() const noexcept;

            // SWS_CORE_00518
            /**
             * \brief Return a textual representation of this ErrorCode.
             * 
             * \return StringView   the error message text
             */
            StringView Message() const noexcept;

            // SWS_CORE_00519
            /**
             * \brief Throw this error as exception.
             * 
             * This function will determine the appropriate exception type for this ErrorCode and throw it. The
             * thrown exception will contain this ErrorCode.
             * 
             */
            void ThrowAsException() const;
        };

        // SWS_CORE_00571
        /**
         * \brief Global operator== for ErrorCode.
         * 
         * Two ErrorCode instances compare equal if the results of their Value() and Domain() functions
         * are equal. The result of SupportData() is not considered for equality.
         * 
         * \param[in] lhs   the left hand side of the comparison
         * \param[in] rhs   the right hand side of the comparison
         * 
         * \return true     if the two instances compare equal
         * \return false    otherwise
         */
        constexpr bool operator==(ErrorCode const &lhs, ErrorCode const &rhs) noexcept;

        // SWS_CORE_00572
        /**
         * \brief Global operator!= for ErrorCode.
         * 
         * Two ErrorCode instances compare equal if the results of their Value() and Domain() functions
         * are equal. The result of SupportData() is not considered for equality.
         * 
         * \param[in] lhs   the left hand side of the comparison 
         * \param[in] rhs   the right hand side of the comparison
         *
         * \return true     if the two instances compare not equal
         * \return false    otherwise
         */
        constexpr bool operator!=(ErrorCode const &lhs, ErrorCode const &rhs) noexcept;
    } // namespace core
    
} // namespace ara


#endif // ARA_CORE_ERROR_CODE_H_
