/**
 * \file utility.h
 * \author Vincent WANG (you@domain.com)
 * \brief 
 * \version 0.1
 * \date 2020-12-08
 * 
 * \copyright Copyright (c) 2020
 * 
 */
#ifndef ARA_CORE_UTILITY_H_
#define ARA_CORE_UTILITY_H_

#include <cstddef>

namespace ara
{
    namespace core
    {
        // SWS_CORE_04200
        /**
         * \brief A non-integral binary type.
         * 
         */
        using Byte = IMPEMENTATION_DEFINED;

        // SWS_CORE_04011
        /**
         * \brief Denote an operation to be performed in-place.
         * 
         * An instance of this type can be passed to certain constructors of ara::core::Optional to denote
         * the intention that construction of the contained type shall be done in-place, i.e. without any
         * copying taking place.
         * 
         */
        struct in_place_t
        {
            // SWS_CORE_04012
            /**
             * \brief Default constructor.
             * 
             */
            explicit in_place_t() = default;
        };

        // SWS_CORE_04013
        /**
         * \brief The singleton instance of in_place_t.
         * 
         */
        constexpr in_place_t in_place;

        // SWS_CORE_04021
        /**
         * \brief Denote a type-distinguishing operation to be performed in-place.
         * 
         * An instance of this type can be passed to certain constructors of ara::core::Variant to denote
         * the intention that construction of the contained type shall be done in-place, i.e. without any
         * copying taking place.
         * 
         * \tparam T 
         */
        template<typename T>
        struct inplace_type_t
        {
            // SWS_CORE_04022
            /**
             * \brief Default constructor.
             * 
             */
            explicit inplace_type_t() = default;
        };

        // SWS_CORE_04031
        /**
         * \brief Denote an index-distinguishing operation to be performed in-place.
         * 
         * An instance of this type can be passed to certain constructors of ara::core::Variant to denote
         * the intention that construction of the contained type shall be done in-place, i.e. without any
         * copying taking place.
         * 
         * \tparam I  -
         */
        template<size_t I>
        struct in_place_index_t
        {
            // SWS_CORE_04032
            /**
             * \brief Default constructor.
             * 
             */
            explicit in_place_index_t() = default;
        };


        // SWS_CORE_04110
        /**
         * \brief Return a pointer to the block of memory that contains the elements of a container.
         * 
         * \tparam Container    a type with a data() method
         * \param[in] c         an instance of Container
         * \return decltype(c.data())   a pointer to the first element of the container
         */
        template<typename Container>
        constexpr auto data(Container &c) -> decltype(c.data());

        // SWS_CORE_04111
        /**
         * \brief Return a const_pointer to the block of memory that contains the elements of a container.
         * 
         * \tparam Container    a type with a data() method
         * \param[in] c         an instance of Container
         * \return decltype(c.data())   a pointer to the first element of the container
         */
        template<typename Container>
        constexpr auto data(Container const &c) -> decltype(c.data());

        // SWS_CORE_04112
        /**
         * \brief Return a pointer to the block of memory that contains the elements of a raw array.
         * 
         * \tparam T    the type of array elements
         * \tparam N    the number of elements in the array
         * 
         * \param[in] array reference to a raw array
         * 
         * \return T* a pointer to the first element of the array
         */
        template<typename T, std::size_t N>
        constexpr T* data(T(&array)[N]) noexcept;
        
        // SWS_CORE_04113
        /**
         * \brief Return a pointer to the block of memory that contains the elements of a std::initializer_list.
         * 
         * \tparam E        the type of elements in the std::initializer_list
         * \param[in] il    the std::initializer_list
         * \return E const* a pointer to the first element of the std::initializer_list
         */
        template<typename E>
        constexpr E const* data(std::initializer_list<E> il) noexcept;

        // SWS_CORE_04120
        /**
         * \brief Return the size of a container.
         * 
         * \tparam Container    a type with a data() method
         * \param[in] c         an instance of Container
         * \return decltype(c.size())   the size of the container
         */
        template<typename Container>
        constexpr auto size(Container const &c) -> decltype(c.size());

        // SWS_CORE_04121
        /**
         * \brief Return the size of a raw array.
         * 
         * \tparam T the type of array elements
         * \tparam N the number of elements in the array
         * 
         * \param[in] array reference to a raw array
         * 
         * \return std::size_t  the size of the array, i.e. N
         */
        template<typename T, std::size_t N>
        constexpr std::size_t size(T const (&array)[N]) noexcept;

        // SWS_CORE_04130
        /**
         * \brief Return whether the given container is empty.
         * 
         * \tparam Container    a type with a empty() method
         * \param[in] c         an instance of Container
         * \return decltype(c.empty())  true if the container is empty, false otherwise
         */
        template<typename Container>
        constexpr auto empty(Container const &c) -> decltype(c.empty());

        // SWS_CORE_04131
        /**
         * \brief Return whether the given raw array is empty.
         * 
         * As raw arrays cannot have zero elements in C++, this function always returns false.
         * 
         * \tparam T    the type of array elements 
         * \tparam N    the number of elements in the array
         * 
         * \param[in] array     the raw array
         * 
         * \return true 
         * \return false    false
         */
        template<typename T, std::size_t N>
        constexpr bool empty(T const (&array)[N]) constexpr;

        // SWS_CORE_04132
        /**
         * \brief Return whether the given std::initializer_list is empty.
         * 
         * \tparam E    the type of elements in the std::initializer_list
         * \param[in] il    the std::initializer_list
         * \return true     if the std::initializer_list is empty
         * \return false    otherwise
         */
        template<typename E>
        constexpr bool empty(std::initializer_list<E> il) noexcept;
    } // namespace core
    
} // namespace ara


#endif // ARA_CORE_UTILITY_H_
