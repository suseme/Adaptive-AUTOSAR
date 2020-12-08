/**
 * \file error_domain.h
 * \author Vincent WANG (you@domain.com)
 * \brief 
 * \version 0.1
 * \date 2020-12-04
 * 
 * \copyright Copyright (c) 2020
 * 
 */
#ifndef ARA_CORE_ERROR_DOMAIN_H_
#define ARA_CORE_ERROR_DOMAIN_H_

#include <cstdint>

namespace ara
{
    namespace core
    {
        #define IMPLEMENTATION_DEFINED std::int32_t

        // SWS_CORE_00110
        /**
         * \brief Encapsulation of an error domain.
         * 
         * An error domain is the controlling entity for ErrorCode’s error code values, and defines the
         * mapping of such error code values to textual representations.
         * This class is a literal type, and subclasses are strongly advised to be literal types as well.
         * 
         */
        class ErrorDomain
        {
            // SWS_CORE_00121
            /**
             * \brief Alias type for a unique ErrorDomain identifier type .
             * 
             */
            using IdType = std::uint64_t;

            // SWS_CORE_00122
            /**
             * \brief Alias type for a domain-specific error code value .
             * 
             */
            using CodeType = std::int32_t;

            // SWS_CORE_00123
            /**
             * \brief Alias type for vendor-specific supplementary data .
             * 
             */
            using SupportDataType = IMPLEMENTATION_DEFINED;

            // SWS_CORE_00131
            /**
             * \brief Copy construction shall be disabled.
             * 
             */
            ErrorDomain(ErrorDomain const &)=delete;

            // SWS_CORE_00132
            /**
             * \brief Move construction shall be disabled.
             * 
             */
            ErrorDomain(ErrorDomain const &&)=delete;

            // SWS_CORE_00135
            /**
             * \brief Construct a new instance with the given identifier.
             * 
             * Identifiers are expected to be system-wide unique.
             * 
             */
            explicit constexpr ErrorDomain(IdType id) noexcept;

            // SWS_CORE_00136
            /**
             * \brief Destructor.
             * 
             * This dtor is non-virtual (and trivial) so that this class can be a literal type. While this class has
             * virtual functions, no polymorphic destruction is needed.
             * 
             */
            ~ErrorDomain()=default;

            // SWS_CORE_00133
            /**
             * \brief Copy assignment shall be disabled.
             * 
             */
            ErrorDomain& operator=(ErrorDomain const &)=delete;

            // SWS_CORE_00134
            /**
             * \brief Move assignment shall be disabled.
             * 
             */
            ErrorDomain& operator=(ErrorDomain const &&)=delete;

            // SWS_CORE_00137
            /**
             * \brief Compare for equality with another ErrorDomain instance.
             * 
             * Two ErrorDomain instances compare equal when their identifiers (returned by Id()) are equal.
             * 
             * \param[in] other     the other instance
             * 
             * \return true         if other is equal to *this
             * \return false        otherwise
             */
            constexpr bool operator==(ErrorDomain const &other) const noexcept;

            // SWS_CORE_00138
            /**
             * \brief Compare for non-equality with another ErrorDomain instance.
             * 
             * \param[in] other     the other instance
             * 
             * \return true         if other is not equal to *this
             * \return false        otherwise
             */
            constexpr bool operator!=(ErrorDomain const &other) const noexcept;

            // SWS_CORE_00151
            /**
             * \brief Return the unique domain identifier.
             * 
             * \return constexpr IdType     the identifier
             */
            constexpr IdType Id() const noexcept;

            // SWS_CORE_00152
            /**
             * \brief Return the name of this error domain.
             * 
             * The returned pointer remains owned by class ErrorDomain and shall not be freed by clients.
             * 
             * \return char const*  the name as a null-terminated string, never nullptr
             */
            virtual char const* Name() const noexcept=0;

            // SWS_CORE_00153
            /**
             * \brief Return a textual representation of the given error code.
             * 
             * It is a Violation if the errorCode did not originate from this error domain, and thus be subject to
             * SWS_CORE_00003.
             * 
             * The returned pointer remains owned by the ErrorDomain subclass and shall not be freed by
             * clients.
             * 
             * \param[in] errorCode     the domain-specific error code
             * 
             * \return char const*      the text as a null-terminated string, never nullptr
             */
            virtual char const * Message(CodeType errorCode) const noexcept=0;

            // SWS_CORE_00154
            /**
             * \brief Throw the given error as exception.
             * 
             * This function will determine the appropriate exception type for the given ErrorCode and throw it.
             * The thrown exception will contain the given ErrorCode.
             * 
             * \param[in] errorCode     the ErrorCode
             */
            virtual void ThrowAsException(ErrorCode const &errorCode) const noexcept(false) = 0;
        };
    } // namespace core
    
} // namespace ara


#endif // ARA_CORE_ERROR_DOMAIN_H_
