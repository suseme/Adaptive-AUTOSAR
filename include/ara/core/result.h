/**
 * \file result.h
 * \author Vincent WANG (you@domain.com)
 * \brief 
 * \version 0.1
 * \date 2020-12-04
 * 
 * \copyright Copyright (c) 2020
 * 
 */
#ifndef ARA_CORE_RESULT_H_
#define ARA_CORE_RESULT_H_

#include "error_code.h"

namespace ara
{
    namespace core
    {
        // SWS_CORE_00701
        /**
         * \brief This class is a type that contains either a value or an error.
         * 
         * \tparam T    the type of value 
         * \tparam E    the type of error
         */
        template<typename T, typename E = ErrorCode>
        class Result final
        {
            // SWS_CORE_00711
            /**
             * \brief Type alias for the type T of values .
             */
            using value_type = T;

            // SWS_CORE_00712
            /**
             * \brief Type alias for the type E of errors .
             */
            using error_type = E;

            // SWS_CORE_00721
            /**
             * \brief Construct a new Result from the specified value (given as lvalue).
             * 
             * \param[in] t     the value to put into the Result
             */
            Result(T const &t);

            // SWS_CORE_00722
            /**
             * \brief Construct a new Result from the specified value (given as rvalue).
             * 
             * \param[in] t     the value to put into the Result
             */
            Result(T const &&t);

            // SWS_CORE_00723
            /**
             * \brief Construct a new Result from the specified error (given as lvalue).
             * 
             * \param[in] e     the error to put into the Result
             */
            Result(E const &e);

            // SWS_CORE_00724
            /**
             * \brief Construct a new Result from the specified error (given as rvalue).
             * 
             * \param[in] e     the error to put into the Result
             */
            Result(E const &&e);

            // SWS_CORE_00725
            /**
             * \brief Copy-construct a new Result from another instance.
             * 
             * \param[in] other     the other instance
             */
            Result(Result const &other);

            // SWS_CORE_00726
            /**
             * \brief Move-construct a new Result from another instance.
             * 
             * \param[in] other     the other instance
             */
            Result(Result const &&other) noexcept(std:is_nothrow_move_constructible<T>::value &&std::is_nothrow_move_constructible<E>::value);

            // SWS_CORE_00727
            /**
             * \brief Destructor.
             * 
             * This destructor is trivial if std::is_trivially_destructible<T>::value && std::is_trivially_
             * destructible<E>::value is true.
             * 
             */
            ~Result();

            // SWS_CORE_00731
            /**
             * \brief Build a new Result from the specified value (given as lvalue).
             * 
             * \param[in] t     the value to put into the Result
             * 
             * \return Result   a Result that contains the value t
             */
            static Result FromValue(T const &t);

            // SWS_CORE_00732
            /**
             * \brief Build a new Result from the specified value (given as rvalue).
             * 
             * \param[in] t     the value to put into the Result
             * 
             * \return Result   a Result that contains the value t
             */
            static Result FromValue(T &&t);

            // SWS_CORE_00733
            /**
             * \brief Build a new Result from a value that is constructed in-place from the given arguments.
             * 
             * This function shall not participate in overload resolution unless: std::is_constructible<T,
             * Args&&...>::value is true, and the first type of the expanded parameter pack is not T, and the
             * first type of the expanded parameter pack is not a specialization of Result
             * 
             * \tparam Args     the types of arguments given to this function
             * \param[in] args  the arguments used for constructing the value
             * 
             * \return Result   a Result that contains a value
             */
            template <typename... Args>
            static Result FromValue(Args &&... args);

            // SWS_CORE_00734
            /**
             * \brief Build a new Result from the specified error (given as lvalue).
             * 
             * \param[in] e     the error to put into the Result
             * 
             * \return Result   a Result that contains the error e
             */
            static Result FromError(E const &e);

            // SWS_CORE_00735
            /**
             * \brief Build a new Result from the specified error (given as rvalue).
             * 
             * \param[in] e     the error to put into the Result
             * 
             * \return Result   a Result that contains the error e
             */
            static Result FromError(E const &&e);

            // SWS_CORE_00736
            /**
             * \brief Build a new Result from an error that is constructed in-place from the given arguments.
             * 
             * This function shall not participate in overload resolution unless: std::is_constructible<E,
             * Args&&...>::value is true, and the first type of the expanded parameter pack is not E, and the
             * first type of the expanded parameter pack is not a specialization of Result
             * 
             * \tparam Args     the types of arguments given to this function
             * 
             * \param[in] args  the arguments used for constructing the error
             * 
             * \return Result   a Result that contains an error
             */
            template <typename.. Args>
            static Result FromError(Args &&... args);

            // SWS_CORE_00741
            /**
             * \brief Copy-assign another Result to this instance.
             * 
             * \param[in] other     the other instance
             * 
             * \return Result&      *this, containing the contents of other
             */
            Result& operator=(Result const &other);

            // SWS_CORE_00742
            /**
             * \brief Move-assign another Result to this instance.
             * 
             * \param[in] other     the other instance
             * 
             * \return Result&      *this, containing the contents of other
             */
            Result& operator=(Result &&other) noexcept(
                  std::is_nothrow_move_constructible<T>::value &&std::is_nothrow_move_assignable<T>::value 
                &&std::is_nothrow_move_constructible<E>::value &&std::is_nothrow_move_assignable<E>::value);

            // SWS_CORE_00743
            /**
             * \brief Put a new value into this instance, constructed in-place from the given arguments.
             * 
             * \tparam Args     the types of arguments given to this function
             * 
             * \param[in] args  the arguments used for constructing the value
             * 
             * \return None
             */
            template <typename... Args>
            void EmplaceValue(Args &&... args);

            // SWS_CORE_00744
            /**
             * \brief Put a new error into this instance, constructed in-place from the given arguments.
             * 
             * \tparam Args     the types of arguments given to this function
             * 
             * \param[in] args  the arguments used for constructing the error
             */
            template <typename... Args>
            void EmplaceError(Args &&... args);

            // SWS_CORE_00745
            /**
             * \brief Exchange the contents of this instance with those of other.
             * 
             * \param[in] other     the other instance
             */
            void Swap(Result &other) noexcept(
                  std::is_nothrow_move_constructible<T>::value &&std::is_nothrow_move_assignable<T>::value
                &&std::is_nothrow_move_constructible<E>::value &&std::is_nothrow_move_assignable<E>::value
            );

            // SWS_CORE_00751
            /**
             * \brief Check whether *this contains a value.
             * 
             * \return true     if *this contains a value
             * \return false    otherwise
             */
            bool hasValue() const noexcept;

            // SWS_CORE_00752
            /**
             * \brief Check whether *this contains a value.
             * 
             * \return true     if *this contains a value
             * \return false    otherwise
             */
            explicit operator bool() const noexcept;

            // SWS_CORE_00753
            /**
             * \brief Access the contained value.
             * 
             * This function’s behavior is undefined if *this does not contain a value.
             * 
             * \return T const&     a const_reference to the contained value
             */
            T const& operator*() const &;

            // SWS_CORE_00759
            /**
             * \brief Access the contained value.
             * 
             * This function’s behavior is undefined if *this does not contain a value.
             * 
             * \return T&&  an rvalue reference to the contained value
             */
            T&& operator*() &&;

            // SWS_CORE_00754
            /**
             * \brief Access the contained value.
             * 
             * This function’s behavior is undefined if *this does not contain a value.
             * 
             * \return T const*     a pointer to the contained value
             */
            T const* operator->() const;

            // SWS_CORE_00755
            /**
             * \brief Access the contained value.
             * 
             * The behavior of this function is undefined if *this does not contain a value.
             * 
             * \return T const&     a const reference to the contained value
             */
            T const& Value() const &;

            // SWS_CORE_00756
            /**
             * \brief Access the contained value.
             * 
             * The behavior of this function is undefined if *this does not contain a value.
             * 
             * \return T&&  an rvalue reference to the contained value
             */
            T&& Value() &&;

            // SWS_CORE_00757
            /**
             * \brief Access the contained error.
             * 
             * The behavior of this function is undefined if *this does not contain an error.
             * 
             * \return E const&     a const reference to the contained error
             */
            E const& Error() const &;

            // SWS_CORE_00758
            /**
             * \brief Access the contained error.
             * 
             * The behavior of this function is undefined if *this does not contain an error.
             * 
             * \return E&&  an rvalue reference to the contained error
             */
            E&& Error() const &&;

            // SWS_CORE_00761
            /**
             * \brief eturn the contained value or the given default value.
             * 
             * If *this contains a value, it is returned. Otherwise, the specified default value is returned, static_
             * cast’d to T.
             * 
             * \tparam U                the type of defaultValue
             * 
             * \param[in] defaultValue  the value to use if *this does not contain a value
             * 
             * \return T                the value
             */
            template <typename U>
            T ValueOr(U &&defaultValue) const &;

            // SWS_CORE_00762
            /**
             * \brief Return the contained value or the given default value.
             * 
             * If *this contains a value, it is returned. Otherwise, the specified default value is returned, static_
             * cast’d to T.
             * 
             * \tparam U                the type of defaultValue
             * \param[in] defaultValue  the value to use if *this does not contain a value
             * \return T                the value
             */
            template<typename U>
            T ValueOr(U &&defaultValue) &&;

            // SWS_CORE_00763
            /**
             * \brief Return the contained error or the given default error.
             * 
             * If *this contains an error, it is returned. Otherwise, the specified default error is returned, static_
             * cast’d to E.
             * 
             * \tparam G                the type of defaultError
             * \param[in] defaultValue  the error to use if *this does not contain an error
             * \return E                the error
             */
            template <typename G>
            E ErrorOr(G &&defaultValue) const;

            // SWS_CORE_00765
            /**
             * \brief Return whether this instance contains the given error.
             * 
             * This call compares the argument error, static_cast’d to E, with the return value from Error().
             * 
             * \tparam G        the type of the error argument error
             * \param[in] error the error to check
             * \return true     if *this contains an error that is equivalent to the
             *                  given error
             * \return false    otherwise
             */
            template <typename G>
            bool CheckError(G &&error) const;

            // SWS_CORE_00766
            /**
             * \brief Return the contained value or throw an exception.
             * 
             * This function does not participate in overload resolution when the compiler toolchain does not
             * support C++ exceptions.
             * 
             * \return T const&     a const reference to the contained value
             */
            T const& ValueOrThrow() const & noexcept(false);

            // SWS_CORE_00769
            /**
             * \brief Return the contained value or throw an exception.
             * 
             * This function does not participate in overload resolution when the compiler toolchain does not
             * support C++ exceptions.
             * 
             * \return T&&  an rvalue reference to the contained value
             * 
             * \exceptions <TYPE>   the exception type associated with the contained error
             */
            T&& ValueOrThrow() && noexcept(false);

            // SWS_CORE_00767
            /**
             * \brief Return the contained value or return the result of a function call.
             * 
             * If *this contains a value, it is returned. Otherwise, the specified callable is invoked and its return
             * value which is to be compatible to type T is returned from this function.
             * 
             * The Callable is expected to be compatible to this interface: T f(E const&);
             * 
             * \tparam F        the type of the Callable f
             * \param[in] f     the Callable
             * \return T        the value
             */
            template <typename F>
            T Resolve(F &&f) const;

            // SWS_CORE_00768
            /**
             * \brief Apply the given Callable to the value of this instance, and return a new Result with the result of
             * the call.
             * 
             * The Callable is expected to be compatible to one of these two interfaces: Result<XXX, E> f(T
             * const&); XXX f(T const&); meaning that the Callable either returns a Result<XXX> or a XXX
             * directly, where XXX can be any type that is suitable for use by class Result.
             * 
             * The return type of this function is decltype(f(Value())) for a template argument F that returns a
             * Result type, and it is Result<decltype(f(Value())), E> for a template argument F that does not
             * return a Result type.
             * 
             * If this instance does not contain a value, a new Result<XXX, E> is still created and returned,
             * with the original error contents of this instance being copied into the new instance.
             * 
             * \tparam F            the type of the Callable f
             * \param[in] f         the Callable
             * \return SEE_BELOW    a new Result instance of the possibly transformed type
             */
            template <typename F>
            auto Bind(F &&f) const -> SEE_BELOW;
        };
    
        // SWS_CORE_00801
        /**
         * \brief Specialization of class Result for "void" values.
         * 
         * \tparam E    the type of error
         */
        template <typename E>
        class Result<void, E> final
        {
            // SWS_CORE_00811
            /**
             * \brief Type alias for the type T of values, always "void" for this specialization .
             */
            using value_type = void;

            // SWS_CORE_00812
            /**
             * \brief Type alias for the type E of errors .
             */
            using error_type = E;

            // SWS_CORE_00821
            /**
             * \brief Construct a new Result with a "void" value.
             * 
             */
            Result() noexcept;

            // SWS_CORE_00823
            /**
             * \brief Construct a new Result from the specified error (given as lvalue).
             * 
             * \param[in] e     the error to put into the Result
             */
            explicit Result(E const &e);

            // SWS_CORE_00824
            /**
             * \brief Construct a new Result from the specified error (given as rvalue).
             * 
             * \param[in] e     the error to put into the Result
             */
            explicit Result(E &&e);

            // SWS_CORE_00825
            /**
             * \brief Copy-construct a new Result from another instance.
             * 
             * \param[in] other     the other instance
             */
            Result(Result const &other);

            // SWS_CORE_00826
            /**
             * \brief Move-construct a new Result from another instance.
             * 
             * \param[in] other     the other instance
             */
            Result(Result &&other) noexcept(std::is_nothrow_move_constructible<E>::value);

            // SWS_CORE_00827
            /**
             * \brief Destructor.
             * 
             * This destructor is trivial if std::is_trivially_destructible<E>::value is true.
             */
            ~Result();

            // SWS_CORE_00831
            /**
             * \brief Build a new Result with "void" as value.
             * 
             * \return Result   a Result that contains a "void" value
             */
            static Result FromValue();

            // SWS_CORE_00834
            /**
             * \brief Build a new Result from the specified error (given as lvalue).
             * 
             * \param[in] e     the error to put into the Result
             * \return Result   a Result that contains the error e
             */
            static Result FromError(E const &e);

            // SWS_CORE_00835
            /**
             * \brief Build a new Result from the specified error (given as rvalue).
             * 
             * \param[in] e     the error to put into the Result
             * \return Result   a Result that contains the error e
             */
            static Result FromError(E const &&e);

            // SWS_CORE_00836
            /**
             * \brief Build a new Result from an error that is constructed in-place from the given arguments.
             * 
             * This function shall not participate in overload resolution unless: std::is_constructible<E,
             * Args&&...>::value is true, and the first type of the expanded parameter pack is not E, and the
             * first type of the expanded parameter pack is not a specialization of Result
             * 
             * \tparam Args     the types of arguments given to this function
             * \param[in] args  the parameter pack used for constructing the error
             * \return Result   a Result that contains an error
             */
            template<typename... Args>
            static Result FromError(Args& ... args);

            // SWS_CORE_00841
            /**
             * \brief Copy-assign another Result to this instance.
             * 
             * \param[in] other     the other instance
             * \return Result&      *this, containing the contents of other
             */
            Result& operator=(Result const &other);

            // SWS_CORE_00842
            /**
             * \brief Move-assign another Result to this instance.
             * 
             * \param[in] other     the other instance
             * \return Result&      *this, containing the contents of other
             * 
             * conditionally noexcept
             */
            Result& operator=(Result &&other) noexcept(
                std::is_nothrow_move_constructible<E>::value && std::is_nothrow_move_assignable<E>::value);

            // SWS_CORE_00843
            /**
             * \brief Put a new value into this instance, constructed in-place from the given arguments.
             * 
             * \tparam Args     the types of arguments given to this function
             * \param[in] args  the arguments used for constructing the value
             */
            template<typename... Args>
            void EmplaceValue(Args &&... args) noexcept;
            
            // SWS_CORE_00844
            /**
             * \brief Put a new error into this instance, constructed in-place from the given arguments.
             * 
             * \tparam Args     the types of arguments given to this function
             * \param[in] args  the arguments used for constructing the error
             */
            template<typename... Args>
            void EmplaceError(Args &&... args);

            // SWS_CORE_00845
            /**
             * \brief Exchange the contents of this instance with those of other.
             * 
             * \param[in] other     the other instance
             */
            void Swap(Result &other) noexcept(
                std::is_nothrow_move_constructible<E>::value && std::is_nothrow_move_assignable<E>::value);

            // SWS_CORE_00851
            /**
             * \brief Check whether *this contains a value.
             * 
             * \return true     if *this contains a value
             * \return false    otherwise
             */
            bool HasValue() const noexcept;

            // SWS_CORE_00852
            /**
             * \brief Check whether *this contains a value.
             * 
             * \return true     if *this contains a value
             * \return false    otherwise
             */
            explicit operator bool () const noexcept;

            // SWS_CORE_00853
            /**
             * \brief Do nothing.
             * This function only exists for helping with generic programming.
             * The behavior of this function is undefined if *this does not contain a value.
             */
            void operator*() const;

            // SWS_CORE_00855
            /**
             * \brief Do nothing.
             * This function only exists for helping with generic programming.
             * The behavior of this function is undefined if *this does not contain a value.
             */
            void Value() const;

            // SWS_CORE_00857
            /**
             * \brief Access the contained error.
             * The behavior of this function is undefined if *this does not contain an error.
             * 
             * \return E const&     a const reference to the contained error
             */
            E const& Error() const &;

            // SWS_CORE_00858
            /**
             * \brief Access the contained error.
             * The behavior of this function is undefined if *this does not contain an error.
             * 
             * \return E&&  an rvalue reference to the contained error
             */
            E&& Error() &&;

            // SWS_CORE_00861
            /**
             * \brief Do nothing.
             * This function only exists for helping with generic programming.
             * 
             * \tparam U    the type of defaultValue
             * \param[in] defaultValue  the value to use if *this does not contain a value
             */
            template<typename U>
            void ValueOr(U &&defaultValue) const;

            // SWS_CORE_00863
            /**
             * \brief Return the contained error or the given default error.
             * If *this contains an error, it is returned. Otherwise, the specified default error is returned, static_
             * cast’d to E.
             * 
             * \tparam G    the type of defaultError
             * \param[in] defaultError  the error to use if *this does not contain an error
             * \return E    the error
             */
            template<typename G>
            E ErrorOr(G &&defaultError) const;

            // SWS_CORE_00865
            /**
             * \brief Return whether this instance contains the given error.
             * This call compares the argument error, static_cast’d to E, with the return value from Error().
             * 
             * \tparam G    the type of the error argument error
             * \param[in] error     the error to check
             * \return true     if *this contains an error that is equivalent to the given error
             * \return false    otherwise
             */
            template<typename G>
            bool CheckError(G &&error) const;

            // SWS_CORE_00866
            /**
             * \brief Return the contained value or throw an exception.
             * This function does not participate in overload resolution when the compiler toolchain does not
             * support C++ exceptions.
             * 
             * \exception <TYPE>    the exception type associated with the contained error
             */
            void ValueOrThrow() const noexcept(false);

            // SWS_CORE_00867
            /**
             * \brief Do nothing or call a function.
             * If *this contains a value, this function does nothing. Otherwise, the specified callable is invoked.
             * The Callable is expected to be compatible to this interface: void f(E const&);
             * This function only exists for helping with generic programming.
             * 
             * \tparam F    the type of the Callable f
             * \param[in] f the Callable
             */
            template<typename F>
            void Resolve(F &&f) const;
        };

        // SWS_CORE_00780
        /**
         * \brief Compare two Result instances for equality.
         * A Result that contains a value is unequal to every Result containing an error. A Result is equal
         * to another Result only if both contain the same type, and the value of that type compares equal.
         * 
         * \tparam T 
         * \tparam E 
         * \param[in] lhs   the left hand side of the comparison 
         * \param[in] rhs   the right hand side of the comparison
         * \return true     if the two instances compare equal
         * \return false    otherwise
         */
        template<typename T, typename E>
        bool operator==(Result<T, E> const &lhs, Result<T, E> const &rhs);

        // SWS_CORE_00781
        /**
         * \brief Compare two Result instances for inequality.
         * A Result that contains a value is unequal to every Result containing an error. A Result is equal
         * to another Result only if both contain the same type, and the value of that type compares equal.
         * 
         * \tparam T 
         * \tparam E 
         * \param[in] lhs   the left hand side of the comparison 
         * \param[in] rhs   the right hand side of the comparison
         * \return true     if the two instances compare unequal
         * \return false    otherwise
         */
        template<typename T, typename E>
        bool operator!=(Result<T, E> const &lhs, Result<T, E> const &rhs);

        // SWS_CORE_00782
        /**
         * \brief Compare a Result instance for equality to a value.
         * A Result that contains no value is unequal to every value. A Result is equal to a value only if the
         * Result contains a value of the same type, and the values compare equal.
         * 
         * \tparam T 
         * \tparam E 
         * \param[in] lhs   the Result instance
         * \param[in] rhs   the value to compare with
         * \return true     if the Result’s value compares equal to the rhs value
         * \return false    otherwise
         */
        template<typename T, typename E>
        bool operator==(Result<T, E> const &lhs, T const &rhs);

        // SWS_CORE_00783
        /**
         * \brief   Compare a Result instance for equality to a value.
         * A Result that contains no value is unequal to every value. A Result is equal to a value only if the
         * Result contains a value of the same type, and the values compare equal.
         * 
         * \tparam T 
         * \tparam E 
         * \param[in] lhs   the value to compare with
         * \param[in] rhs   the Result instance
         * \return true     if the Result’s value compares equal to the lhs value
         * \return false    otherwise
         */
        template<typename T, typename E>
        bool operator==(T const &lhs, Result<T, E> const &rhs);

        // SWS_CORE_00784
        /**
         * \brief Compare a Result instance for inequality to a value.
         * A Result that contains no value is unequal to every value. A Result is equal to a value only if the
         * Result contains a value of the same type, and the values compare equal.
         * 
         * \tparam T 
         * \tparam E 
         * \param[in] lhs   the Result instance
         * \param[in] rhs   the value to compare with
         * \return true     if the Result’s value compares unequal to the rhs value
         * \return false    otherwise
         */
        template<typename T, typename E>
        bool operator!=(Result<T, E> const &lhs, T const &rhs);

        // SWS_CORE_00785
        /**
         * \brief Compare a Result instance for inequality to a value.
         * A Result that contains no value is unequal to every value. A Result is equal to a value only if the
         * Result contains a value of the same type, and the values compare equal.
         * 
         * \tparam T 
         * \tparam E 
         * \param[in] lhs   the value to compare with
         * \param[in] rhs   the Result instance
         * \return true     if the Result’s value compares unequal to the lhs value
         * \return false    otherwise
         */
        template<typename T, typename E>
        bool operator!=(T const &lhs, Result<T, E> const &rhs);]
        
        // SWS_CORE_00786
        /**
         * \brief Compare a Result instance for equality to an error.
         * A Result that contains no error is unequal to every error. A Result is equal to an error only if the
         * Result contains an error of the same type, and the errors compare equal.
         * 
         * \tparam T 
         * \tparam E 
         * \param[in] lhs   the Result instance
         * \param[in] rhs   the error to compare with
         * \return true     if the Result’s error compares equal to the rhs error
         * \return false    otherwise
         */
        template<typename T, typename E>
        bool operator==(Result<T, E> const &lhs, E const &rhs);

        // SWS_CORE_00787
        /**
         * \brief Compare a Result instance for equality to an error.
         * A Result that contains no error is unequal to every error. A Result is equal to an error only if the
         * Result contains an error of the same type, and the errors compare equal.
         * 
         * \tparam T 
         * \tparam E 
         * \param[in] lhs   the error to compare with
         * \param[in] rhs   the Result instance
         * \return true     if the Result’s error compares equal to the lhs error
         * \return false    otherwise
         */
        template<typename T, typename E>
        bool operator==(E const &lhs, Result<T, E> const &rhs);

        // SWS_CORE_00788
        /**
         * \brief Compare a Result instance for inequality to an error.
         * A Result that contains no error is unequal to every error. A Result is equal to an error only if the
         * Result contains an error of the same type, and the errors compare equal.
         * 
         * \tparam T 
         * \tparam E 
         * \param[in] lhs   the Result instance 
         * \param[in] rhs   the error to compare with
         * \return true     if the Result’s error compares unequal to the rhs error
         * \return false    otherwise
         */
        template<typename T, typename E>
        bool operator!=(Result<T, E> const &lhs, E const &rhs);

        // SWS_CORE_00789
        /**
         * \brief Compare a Result instance for inequality to an error.
         * A Result that contains no error is unequal to every error. A Result is equal to an error only if the
         * Result contains an error of the same type, and the errors compare equal.
         * 
         * \tparam T 
         * \tparam E 
         * \param[in] lhs   the error to compare with 
         * \param[in] rhs   the Result instance
         * \return true     if the Result’s error compares unequal to the lhs error
         * \return false    otherwise
         */
        template<typename T, typename E>
        bool operator!=(E const &lhs, Result<T, E> const &rhs);

        // SWS_CORE_00796
        /**
         * \brief Swap the contents of the two given arguments.
         * 
         * \tparam T 
         * \tparam E 
         * \param[in] lhs   one instance
         * \param[in] rhs   another instance
         */
        template<typename T, typename E>
        void swap(Result<T, E> &lhs, Result<T, E> &rhs) noexcept(noexcept(lhs.Swap(rhs)));


    } // namespace core
    
} // namespace ara

#endif // ARA_CORE_RESULT_H_
