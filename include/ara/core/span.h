/**
 * \file span.h
 * \author Vincent WANG (you@domain.com)
 * \brief 
 * \version 0.1
 * \date 2020-12-08
 * 
 * \copyright Copyright (c) 2020
 * 
 */
#ifndef ARA_CORE_SPAN_H_
#define ARA_CORE_SPAN_H_

#include <cstddef>
#include <iterator>

namespace ara
{
    namespace core
    {
        // SWS_CORE_01901
        /**
         * \brief A constant for creating Spans with dynamic sizes.
         * 
         * The constant is always set to std::numeric_limits<std::size_t>::max().
         * 
         */
        constexpr std::size_t dynamic_extent = std::numeric_limits<std::size_t>::max();

        // SWS_CORE_01900
        /**
         * \brief A view over a contiguous sequence of objects.
         * 
         * \tparam T        the type of elements in the Span 
         * \tparam Extent   the extent to use for this Span
         */
        template<typename T, std::size_t Extent = dynamic_extent>
        class Span
        {
            // SWS_CORE_01911
            /**
             * \brief Alias for the type of elements in this Span.
             * 
             */
            using element_type = T;

            // SWS_CORE_01912
            /**
             * \brief Alias for the type of values in this Span.
             * 
             */
            using value_type = typename std::remove_cv<element_type>::type;

            // SWS_CORE_01913
            /**
             * \brief Alias for the type of parameters that indicate an index into the Span.
             * 
             */
            using index_type = std::size_t;

            // SWS_CORE_01914
            /**
             * \brief Alias for the type of parameters that indicate a difference of indexes into the Span.
             * 
             */
            using difference_type = std::ptrdiff_t;

            // SWS_CORE_01921
            /**
             * \brief Alias for the type of parameters that indicate a size or a number of values.
             * 
             * \note This is an AUTOSAR addition that is not contained in std::span.
             */
            using size_type = index_type;

            // SWS_CORE_01915
            /**
             * \brief Alias type for a pointer to an element.
             * 
             */
            using pointer = element_type*;

            // SWS_CORE_01916
            /**
             * \brief Alias type for a reference to an element.
             * 
             */
            using reference = element_type&;

            // SWS_CORE_01917
            /**
             * \brief The type of an iterator to elements.
             * 
             * This iterator shall implement the concepts RandomAccessIterator, ContiguousIterator, and
             * ConstexprIterator.
             * 
             */
            using iterator = implementation_defined;

            // SWS_CORE_01918
            /**
             * \brief The type of a const_iterator to elements.
             * 
             * This iterator shall implement the concepts RandomAccessIterator, ContiguousIterator, and
             * ConstexprIterator.
             * 
             */
            using const_iterator = implementation_defined;

            // SWS_CORE_01919
            /**
             * \brief The type of a reverse_iterator to elements.
             * 
             */
            using reverse_iterator = std::reverse_iterator<iterator>;

            // SWS_CORE_01920
            /**
             * \brief The type of a const_reverse_iterator to elements.
             * 
             */
            using const_reverse_iterator = std_reverse_iterator<const_iterator>;

            // SWS_CORE_01931
            /**
             * \brief A constant reflecting the configured Extent of this Span.
             * 
             */
            constexpr index_type extent = Extent;

            // SWS_CORE_01941
            /**
             * \brief Default constructor.
             * This constructor shall not participate in overload resolution unless Extent <= 0 is true.
             * 
             */
            constexpr Span() noexcept;

            // SWS_CORE_01942
            /**
             * \brief Construct a new Span from the given pointer and size.
             * 
             * [ptr, ptr + count) shall be a valid range. If Extent is not equal to dynamic_extent, then count
             * shall be equal to Extent.
             * 
             * \param[in] ptr   the pointer
             * \param[in] count the number of elements to take from ptr
             */
            constexpr Span(pointer ptr, index_type count);

            // SWS_CORE_01943
            /**
             * \brief Construct a new Span from the open range between [firstElem, lastElem).
             * 
             * [first, last) shall be a valid range. If @ extent is not equal to dynamic_extent, then (last - first)
             * shall be equal to Extent.
             * 
             * \param[in] firstElem pointer to the first element 
             * \param[in] lastElem  pointer to past the last element
             */
            constexpr Span(pointer firstElem, pointer lastElem);

            // SWS_CORE_01944
            /**
             * \brief Construct a new Span from the given raw array.
             * This constructor shall not participate in overload resolution unless: Extent == dynamic_extent ||
             * N == Extent is true, and std::remove_pointer<decltype(ara::core::data(arr))>::type(*)[] is
             * convertible to T(*)[].
             * 
             * \tparam N    the size of the raw array
             * 
             * \param[in] arr   the raw array
             */
            template<std::size_t N>
            constexpr Span(element_type(&arr)[N]) noexcept;

            // SWS_CORE_01945
            /**
             * \brief Construct a new Span from the given Array.
             * This constructor shall not participate in overload resolution unless: Extent == dynamic_extent ||
             * N == Extent is true, and std::remove_pointer<decltype(ara::core::data(arr))>::type(*)[] is
             * convertible to T(*)[].
             * 
             * \tparam N the size of the Array
             * \param[in] arr   the array
             */
            template<std::size_t N>
            constexpr Span(Array<value_type, N> &arr) noexcept;

            // SWS_CORE_01946
            /**
             * \brief Construct a new Span from the given const Array.
             * This constructor shall not participate in overload resolution unless: Extent == dynamic_extent ||
             * N == Extent is true, and std::remove_pointer<decltype(ara::core::data(arr))>::type(*)[] is
             * convertible to T(*)[].
             * 
             * \tparam N the size of the Array
             * \param[in] arr   the array
             */
            template<std::size_t N>
            constexpr Span(Array<value_type, N> const &arr) noexcept;

            // SWS_CORE_01947
            /**
             * \brief Construct a new Span from the given container.
             * [ara::core::data(cont), ara::core::data(cont) + ara::core::size(cont)) shall be a valid range. If
             * Extent is not equal to dynamic_extent, then ara::core::size(cont) shall be equal to Extent.
             * These constructors shall not participate in overload resolution unless: Container is not a
             * specialization of Span, Container is not a specialization of Array, std::is_
             * array<Container>::value is false, ara::core::data(cont) and ara::core::size(cont) are both
             * well-formed, and std::remove_pointer<decltype(ara::core::data(cont))>::type(*)[] is convertible
             * to T(*)[].
             * 
             * \tparam Container    the type of container
             * 
             * \param[in] cont  the container
             */
            template<typename Container>
            constexpr Span(Container &cont);

            // SWS_CORE_01948
            /**
             * \brief Construct a new Span from the given const container.
             * 
             * [ara::core::data(cont), ara::core::data(cont) + ara::core::size(cont)) shall be a valid range. If
             * Extent is not equal to dynamic_extent, then ara::core::size(cont) shall be equal to Extent.
             * 
             * These constructors shall not participate in overload resolution unless: Container is not a
             * specialization of Span, Container is not a specialization of Array, std::is_
             * array<Container>::value is false, ara::core::data(cont) and ara::core::size(cont) are both
             * well-formed, and std::remove_pointer<decltype(ara::core::data(cont))>::type(*)[] is convertible
             * to T(*)[].
             * 
             * \tparam Container the type of container
             * \param[in] cont  the container
             */
            template<typename Container>
            constexpr Span(Container const &cont);

            // SWS_CORE_01949
            /**
             * \brief Copy construct a new Span from another instance.
             * 
             * \param[in] other the other instance
             */
            constexpr Span(Span const &other) noexcept = default;

            // SWS_CORE_01950
            /**
             * \brief Converting constructor.
             * 
             * This ctor allows construction of a cv-qualified Span from a normal Span, and also of a
             * dynamic_extent-Span<> from a static extent-one.
             * 
             * \tparam U the type of elements within the other Span
             * \tparam N the Extent of the other Span
             * 
             * \param[in] s the other Span instance
             */
            template<typename U, std::size_t N>
            constexpr Span(Span<U, N> const &s) noexcept;

            // SWS_CORE_01951
            /**
             * \brief Destructor
             * 
             */
            ~Span() noexcept = default;

            // SWS_CORE_01952
            /**
             * \brief This operator is not constexpr because that would make it implicitly const in C++11.
             * 
             * \param[in] other     the other instance
             * \return Span&        *this
             */
            Span& operator=(Span const &other) noexcept = default;

            // SWS_CORE_01961
            /**
             * \brief Return a subspan containing only the first elements of this Span.
             * 
             * \tparam Count    the number of elements to take over
             * \return Span<element_type, Count>  the subspan
             */
            template<std::size_t Count>
            constexpr Span<element_type, Count> first() const;

            // SWS_CORE_01962
            /**
             * \brief Return a subspan containing only the first elements of this Span.
             * 
             * \param[in] count     the number of elements to take over
             * \return Span<element_type, dynamic_extent>     the subspan
             */
            constexpr Span<element_type, dynamic_extent> first(index_type count) const;

            // SWS_CORE_01963
            /**
             * \brief Return a subspan containing only the last elements of this Span.
             * 
             * \tparam Count    the number of elements to take over
             * \return Span<element_type, Count>  the subspan
             */
            template<std::size_t Count>
            constexpr Span<element_type, Count> last() const;

            // SWS_CORE_01964
            /**
             * \brief Return a subspan containing only the last elements of this Span.
             * 
             * \param[in] count the number of elements to take over
             * \return Span<element_type, dynamic_extent> 
             */
            constexpr Span<element_type, dynamic_extent> last(index_type count) const;

            // SWS_CORE_01965
            /**
             * \brief Return a subspan of this Span.
             * 
             * The second template argument of the returned Span type is:
             * Count != dynamic_extent ? Count : (Extent != dynamic_extent ? Extent - Offset : dynamic_
             * extent)
             * 
             * \tparam Offset   offset into this Span from which to start
             * \tparam Count    the number of elements to take over
             * \return Span<element_type, SEE_BELOW>    the subspan
             */
            template<std::size_t Offset, std::size_t Count = dynamic_extent>
            constexpr auto subspan() const -> Span<element_type, SEE_BELOW>;

            // SWS_CORE_01966
            /**
             * \brief Return a subspan of this Span.
             * 
             * \param[in] offset    offset into this Span from which to start 
             * \param[in] count     the number of elements to take over
             * \return Span<element_type, dynamic_extent>     the subspan
             */
            constexpr Span<element_type, dynamic_extent> subspan(index_type offset, index_type count=dynamic_extent) const;

            // SWS_CORE_01967
            /**
             * \brief Return the size of this Span.
             * 
             * \return index_type     the number of elements contained in this Span
             */
            constexpr index_type size() const noexcept;

            // SWS_CORE_01968
            /**
             * \brief Return the size of this Span in bytes.
             * 
             * \return index_type     the number of bytes covered by this Span
             */
            constexpr index_type size_bytes() const noexcept;

            // SWS_CORE_01969
            /**
             * \brief Return whether this Span is empty.
             * 
             * \return true     if this Span contains 0 elements
             * \return false    otherwise
             */
            constexpr bool empty() const noexcept;

            // SWS_CORE_01970
            /**
             * \brief Return a reference to the n-th element of this Span.
             * 
             * \param[in] idx   the index into this Span
             * \return reference  the reference
             */
            constexpr reference operator[](index_type idx) const;

            // SWS_CORE_01971
            /**
             * \brief Return a pointer to the start of the memory block covered by this Span.
             * 
             * \return pointer    the pointer
             */
            constexpr pointer data() const noexcept;

            // SWS_CORE_01972
            /**
             * \brief Return an iterator pointing to the first element of this Span.
             * 
             * \return iterator   the iterator
             */
            constexpr iterator begin() const noexcept;

            // SWS_CORE_01973
            /**
             * \brief Return an iterator pointing past the last element of this Span.
             * 
             * \return iterator   the iterator
             */
            constexpr iterator end() const noexcept;

            // SWS_CORE_01974
            /**
             * \brief Return a const_iterator pointing to the first element of this Span.
             * 
             * \return const_iterator     the const_iterator
             */
            constexpr const_iterator cbegin() const noexcept;

            // SWS_CORE_01975
            /**
             * \brief Return a const_iterator pointing past the last element of this Span.
             * 
             * \return const_iterator   the const_iterator
             */
            constexpr const_iterator cend() const noexcept;

            // SWS_CORE_01976
            /**
             * \brief Return a reverse_iterator pointing to the last element of this Span.
             * 
             * \return reverse_iterator     the reverse_iterator
             */
            constexpr reverse_iterator rbegin() const noexcept;

            // SWS_CORE_01977
            /**
             * \brief Return a reverse_iterator pointing past the first element of this Span.
             * 
             * \return reverse_iterator     the reverse_iterator
             */
            constexpr reverse_iterator rend() const noexcept;

            // SWS_CORE_01978
            /**
             * \brief Return a const_reverse_iterator pointing to the last element of this Span.
             * 
             * \return const_reverse_iterator     the const_reverse_iterator
             */
            constexpr const_reverse_iterator crbegin() const noexcept;

            // SWS_CORE_01979
            /**
             * \brief Return a const_reverse_iterator pointing past the first element of this Span.
             * 
             * \return const_reverse_iterator   the reverse_iterator
             */
            constexpr const_reverse_iterator crend() const noexcept;
        };

        // SWS_CORE_01990
        /**
         * \brief 
         * 
         * \tparam T    the type of elements
         * 
         * \param[in] ptr   the pointer
         * \param[in] count the number of elements to take from ptr
         * 
         * \return Span<T>  the new Span
         */
        template<typename T>
        constexpr Span<T> MakeSpan(T *ptr, typename Span<T>::index_type count);

        // SWS_CORE_01991
        /**
         * \brief Create a new Span from the open range between [firstElem, lastElem).
         * 
         * \tparam T    the type of elements
         * \param[in] firstElem     pointer to the first element
         * \param[in] lastElem      pointer to past the last element
         * \return Span<T>  the new Span
         */
        template<typename T>
        constexpr Span<T> MakeSpan(T *firstElem, T *lastElem);

        // SWS_CORE_01992
        /**
         * \brief Create a new Span from the given raw array.
         * 
         * \tparam T    the type of elements
         * \tparam N    the size of the raw array
         * 
         * \param[in] arr   the raw array
         * 
         * \return Span<T, N>   the new Span
         */
        template<typename T, std::size_t N>
        constexpr Span<T, N> MakeSpan(T(&arr)[N]) noexcept;

        // SWS_CORE_01993
        /**
         * \brief Create a new Span from the given container.
         * 
         * \tparam Container    the type of container
         * \param[in] cont      the container
         * \return Span<typename Container::value_type>     the new Span
         */
        template<typename Container>
        constexpr Span<typename Container::value_type> MakeSpan(Container &cont);

        // SWS_CORE_01994
        /**
         * \brief Create a new Span from the given const container.
         * 
         * \tparam Container    the type of container
         * \param[in] cont      the container
         * \return Span<typename Container::value_type const>   the new Span
         */
        template<typename Container>
        constexpr Span<typename Container::value_type const> MakeSpan(Container const &cont);

    } // namespace core
    
} // namespace ara


#endif // ARA_CORE_SPAN_H_