/**
 * \file instance_specifier.h
 * \author Vincent WANG (you@domain.com)
 * \brief 
 * \version 0.1
 * \date 2020-12-08
 * 
 * \copyright Copyright (c) 2020
 * 
 */
#ifndef ARA_CORE_INSTANCE_SPECIFIER_H_
#define ARA_CORE_INSTANCE_SPECIFIER_H_

namespace ara
{
    namespace core
    {
        // SWS_CORE_08001
        /**
         * \brief class representing an AUTOSAR Instance Specifier, which is basically an AUTOSAR
         * shortname-path wrapper.
         * 
         */
        class InstanceSpecifier final
        {
            // SWS_CORE_08021
            /**
             * \brief throwing ctor from meta-model string
             * 
             * \param[in] metaModelIdentifier   stringified meta model identifier (short name path)
             *                                  where path separator is ’/’. Lifetime of underlying
             *                                  string has to exceed the lifetime of the constructed
             *                                  InstanceSpecifier.
             * 
             * \exceptions CoreException    in case the given metaModelIdentifier is not a valid
             *                              meta-model identifier/short name path.
             */
            explicit InstanceSpecifier(StringView metaModelIdentifier);

            // SWS_CORE_08029
            /**
             * \brief Destructor
             * 
             */
            ~InstanceSpecifier() noexcept;

            // SWS_CORE_08032
            /**
             * \brief Create a new instance of this class.
             * 
             * \param[in] metaModelIdentifier   stringified form of InstanceSpecifier
             * \return Result<InstanceSpecifier>    a Result, containing either a syntactically valid
             *                                      InstanceSpecifier, or an ErrorCode
             * 
             * \errors CoreErrc::kInvalidMetaModelShortname if any of the path elements of metaModelIdentifier is
             *                                              missing or contains invalid characters
             *         CoreErrc::kInvalidMetaModelPath      if the metaModelIdentifier is not a valid path to a
             *                                              model element
             */
            static Result<InstanceSpecifier> Create(StringView metaModelIdentifier);

            // SWS_CORE_08042
            /**
             * \brief eq operator to compare with other InstanceSpecifier instance.
             * 
             * \param[in] other     InstanceSpecifier instance to compare this one with.
             * \return true         in case both InstanceSpecifiers are denoting
             *                      exactly the same model element
             * \return false        else
             */
            bool operator==(InstanceSpecifier const &other) const noexcept;

            // SWS_CORE_08043
            /**
             * \brief eq operator to compare with other InstanceSpecifier instance.
             * 
             * \param[in] other     string representation to compare this one with.
             * \return true         in case this InstanceSpecifiers is denoting
             *                      exactly the same model element as other
             * \return false        else
             */
            bool operator==(StringView other) const noexcept;

            // SWS_CORE_08044
            /**
             * \brief uneq operator to compare with other InstanceSpecifier instance.
             * 
             * \param[in] other     InstanceSpecifier instance to compare this one with.
             * \return true         else
             * \return false        false in case both InstanceSpecifiers are denoting
             *                      exactly the same model element
             */
            bool operator!=(InstanceSpecifier const &other) const noexcept;

            // SWS_CORE_08045
            /**
             * \brief uneq operator to compare with other InstanceSpecifier string representation.
             * 
             * \param[in] other     string representation to compare this one with.
             * \return true         else
             * \return false        in case this InstanceSpecifiers is denoting
             *                      exactly the same model element as other
             */
            bool operator!=(StringView other) const noexcept;

            // SWS_CORE_08046
            /**
             * \brief lower than operator to compare with other InstanceSpecifier for ordering purposes (f.i. when
             * collecting identifiers in maps).
             * 
             * \param[in] other     InstanceSpecifier instance to compare this one with.
             * \return true         in case this InstanceSpecifiers is lexically lower
             *                      than other
             * \return false        else
             */
            bool operator<(InstanceSpecifier const &other) const noexcept;

            // SWS_CORE_08041
            /**
             * \brief method to return the stringified form of InstanceSpecifier
             * 
             * \return StringView   stringified form of InstanceSpecifier. Lifetime of the
             *                      underlying string is only guaranteed for the lifetime
             *                      of the underlying string of the StringView passed to
             *                      the constructor.
             */
            StringView ToString() const noexcept;

            // 
        };
    } // namespace core
    
} // namespace ara


#endif // ARA_CORE_INSTANCE_SPECIFIER_H_
