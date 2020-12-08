/**
 * \file future.h
 * \author Vincent WANG (you@domain.com)
 * \brief 
 * \version 0.1
 * \date 2020-12-04
 * 
 * \copyright Copyright (c) 2020
 * 
 */
#ifndef ARA_CORE_FUTURE_H_
#define ARA_CORE_FUTURE_H_

#include <cstdint>

namespace ara
{
    namespace core
    {
        // SWS_CORE_00361
        /**
         * \brief Specifies the state of a Future as returned by wait_for() and wait_until().
         * 
         * These definitions are equivalent to the ones from std::future_status. However, no item
         * equivalent to std::future_status::deferred is available here.
         * 
         * The numerical values of the enum items are implementation-defined.
         * 
         */
        enum class future_status : uint8_t
        {
            ready,      /*< the shared state is ready */
            timeout,    /*< the shared state did not become ready before the
                            specified timeout has passed */
        };

        // SWS_CORE_00321
        /**
         * \brief Provides ara::core specific Future operations to collect the results of an asynchronous call.
         * 
         * \tparam T    the type of values 
         * \tparam E    the type of errors
         */
        template <typename T, typename E = ErrorCode>
        class Future final
        {
            // SWS_CORE_00322
            /**
             * \brief Default constructor.
             * This function shall behave the same as the corresponding std::future function.
             * 
             */
            Future() noexcept = default;

            // SWS_CORE_00334
            /**
             * \brief Copy constructor shall be disabled.
             * 
             */
            Future(Future const &) = delete;

            // SWS_CORE_00323
            /**
             * \brief Move construct from another instance.
             * This function shall behave the same as the corresponding std::future function.
             * 
             * \param[in] other     the other instance
             */
            Future(Future &&other) noexcept;

            // SWS_CORE_00333
            /**
             * \brief Destructor for Future objects.
             * This function shall behave the same as the corresponding std::future function.
             * 
             */
            ~Future();

            // SWS_CORE_00335
            /**
             * \brief Copy assignment operator shall be disabled.
             * 
             * \return Future& 
             */
            Future& operator=(Future const &) = delete;

            // SWS_CORE_00325
            /**
             * \brief Move assign from another instance.
             * This function shall behave the same as the corresponding std::future function.
             * 
             * \param[in] other     the other instance
             * \return Future&      *this
             */
            Future& operator=(Future &&other) noexcept;

            // SWS_CORE_00326
            /**
             * \brief Get the value.
             * 
             * This function shall behave the same as the corresponding std::future function.
             * 
             * This function does not participate in overload resolution when the compiler toolchain does not
             * support C++ exceptions.
             * 
             * \return T    value of type T
             * 
             * \errors Domain:error     the error that has been put into the corresponding
             *                          Promise via Promise::SetError
             */
            T get();

            // SWS_CORE_00336
            /**
             * \brief Get the result.
             * 
             * Similar to get(), this call blocks until the value or an error is available. However, this call will
             * never throw an exception.
             * 
             * \return Result<T, E>     a Result with either a value or an error
             * 
             * \errors Domain:error     the error that has been put into the corresponding
             *                          Promise via Promise::SetError
             */
            Result<T, E> GetResult() noexcept;

            // SWS_CORE_00327
            /**
             * \brief Checks if the Future is valid, i.e. if it has a shared state.
             * 
             * This function shall behave the same as the corresponding std::future function.
             * 
             * \return true     if the Future is usable
             * \return false    otherwise
             */
            bool valid() const noexcept;

            // SWS_CORE_00328
            /**
             * \brief Wait for a value or an error to be available.
             * 
             * This function shall behave the same as the corresponding std::future function.
             * 
             */
            void wait() const;

            // SWS_CORE_00329
            /**
             * \brief Wait for the given period, or until a value or an error is available.
             * 
             * This function shall behave the same as the corresponding std::future function.
             * 
             * \tparam Rep 
             * \tparam Period 
             * 
             * \param[in] timeoutDuration   maximal duration to wait for
             * 
             * \return future_status        status that indicates whether the timeout hit or if a
             *                              value is available
             */
            template<typename Rep, typename Period>
            future_status wait_for(std::chrono::duration<Rep, Period> const &timeoutDuration) const;

            // SWS_CORE_00330
            /**
             * \brief Wait until the given time, or until a value or an error is available.
             * 
             * This function shall behave the same as the corresponding std::future function.
             * 
             * \tparam Clock 
             * \tparam Duration 
             * \param[in] deadline      latest point in time to wait
             * \return future_status    status that indicates whether the time was reached
             *                          or if a value is available
             */
            template<typename Clock, typename Duration>
            future_status wait_until(std::chrono::time_point<Clock, Duration> const &deadline) const;

            // SWS_CORE_00331
            /**
             * \brief Register a callable that gets called when the Future becomes ready.
             * 
             * When func is called, it is guaranteed that get() and GetResult() will not block.
             * 
             * func may be called in the context of this call or in the context of Promise::set_value() or
             * Promise::SetError() or somewhere else.
             * 
             * The return type of then depends on the return type of func (aka continuation).
             * 
             * Let U be the return type of the continuation (i.e. a type equivalent to std::result_
             * of<std::decay<F>::type(Future<T,E>)>::type). If U is Future<T2,E2> for some types T2, E2,
             * then the return type of then() is Future<T2,E2>. This is known as implicit Future unwrapping. If
             * U is Result<T2,E2> for some types T2, E2, then the return type of then() is Future<T2,E2>.
             * This is known as implicit Result unwrapping. Otherwise it is Future<U,E>.
             * 
             * \tparam F 
             * \param[in] func              a callable to register
             * \return Future<SEE_BELOW>    a new Future instance for the result of the
             *                              continuation
             */
            template<typename F>
            auto then(F &&func) -> Future<SEE_BELOW>;

            // SWS_CORE_00332
            /**
             * \brief Return whether the asynchronous operation has finished.
             * 
             * If this function returns true, get(), GetResult() and the wait calls are guaranteed not to block.
             * 
             * \return true     if the Future contains a value or an error
             * \return false    otherwise
             */
            bool is_ready() const;
        };

        // SWS_CORE_06221
        /**
         * \brief Specialization of class Future for "void" values.
         * 
         * \tparam E    the type of error
         */
        template<typename E>
        class Future<void, E> final
        {
            // SWS_CORE_06222
            /**
             * \brief Default constructor.
             * This function shall behave the same as the corresponding std::future function.
             * 
             */
            Future() noexcept;

            // SWS_CORE_06234
            /**
             * \brief Copy constructor shall be disabled.
             * 
             * \param[in] other 
             */
            Future(Future const &other) = delete;

            // SWS_CORE_06223
            /**
             * \brief Move construct from another instance.
             * This function shall behave the same as the corresponding std::future function.
             * 
             * \param[in] other     the other instance
             */
            Future(Future &&other) noexcept;

            // SWS_CORE_06233
            /**
             * \brief Destructor for Future objects.
             * This function shall behave the same as the corresponding std::future function.
             * 
             */
            ~Future();

            // SWS_CORE_06235
            /**
             * \brief Copy assignment operator shall be disabled.
             * 
             * \param[in] other 
             * \return Future& 
             */
            Future& operator=(Future const &other) = delete;

            // SWS_CORE_06225
            /**
             * \brief Move assign from another instance.
             * This function shall behave the same as the corresponding std::future function.
             * 
             * \param[in] other     the other instance
             * 
             * \return Future&      *this
             */
            Future& operator=(Future &&other) noexcept;

            // SWS_CORE_06226
            /**
             * \brief Get the value.
             * 
             * This function shall behave the same as the corresponding std::future function.
             * 
             * This function does not participate in overload resolution when the compiler toolchain does not
             * support C++ exceptions.
             * 
             * \errors Domain:error     the error that has been put into the corresponding
             *                          Promise via Promise::SetError
             */
            void get();

            // SWS_CORE_06236
            /**
             * \brief Get the result.
             * 
             * Similar to get(), this call blocks until the value or an error is available. However, this call will
             * never throw an exception.
             * 
             * \return Result<void, E>  a Result with either a value or an error
             * 
             * \errors Domain:error     the error that has been put into the corresponding
             *                          Promise via Promise::SetError
             */
            Result<void, E> GetResult() noexcept;

            // SWS_CORE_06227
            /**
             * \brief Checks if the Future is valid, i.e. if it has a shared state.
             * 
             * This function shall behave the same as the corresponding std::future function.
             * 
             * \return true     if the Future is usable
             * \return false    otherwise
             */
            bool valid() const noexcept;

            // SWS_CORE_06228
            /**
             * \brief Wait for a value or an error to be available.
             * 
             * This function shall behave the same as the corresponding std::future function.
             * 
             */
            void wait() const;

            // SWS_CORE_06229
            /**
             * \brief Wait for the given period, or until a value or an error is available.
             * 
             * This function shall behave the same as the corresponding std::future function.
             * 
             * \tparam Rep 
             * \tparam Period 
             * \param[in] timeoutDuration   maximal duration to wait for
             * \return future_status        status that indicates whether the timeout hit or if a
             *                              value is available
             */
            template<typename Rep, typename Period>
            future_status wait_for(std::chrono::duration<Rep, Period> const &timeoutDuration) const;

            // SWS_CORE_06230
            /**
             * \brief Wait until the given time, or until a value or an error is available.
             * This function shall behave the same as the corresponding std::future function.
             * 
             * \tparam Clock 
             * \tparam Duration 
             * \param[in] deadline      latest point in time to wait
             * \return future_status    status that indicates whether the time was reached
             *                          or if a value is available
             */
            template<typename Clock, typename Duration>
            future_status wait_until(std::chrono::time_point<Clock, Duration> const &deadline) const;

            // SWS_CORE_06231
            /**
             * \brief Register a callable that gets called when the Future becomes ready.
             * 
             * When func is called, it is guaranteed that get() and GetResult() will not block.
             * 
             * func may be called in the context of this call or in the context of Promise::set_value() or
             * Promise::SetError() or somewhere else.
             * 
             * The return type of then depends on the return type of func (aka continuation).
             * 
             * Let U be the return type of the continuation (i.e. a type equivalent to std::result_
             * of<std::decay<F>::type(Future<T,E>)>::type). If U is Future<T2,E2> for some types T2, E2,
             * then the return type of then() is Future<T2,E2>. This is known as implicit Future unwrapping. If
             * U is Result<T2,E2> for some types T2, E2, then the return type of then() is Future<T2,E2>.
             * This is known as implicit Result unwrapping. Otherwise it is Future<U,E>.
             * 
             * \tparam F 
             * \param[in] func  a callable to register
             * \return Future<SEE_BELOW>    a new Future instance for the result of the
             *                              continuation
             */
            template<typename F>
            auto then(F &&func) -> Future<SEE_BELOW>;

            // SWS_CORE_06232
            /**
             * \brief Return whether the asynchronous operation has finished.
             * 
             * If this function returns true, get(), GetResult() and the wait calls are guaranteed not to block.
             * 
             * \return true     if the Future contains a value or an error
             * \return false    otherwise
             */
            bool is_ready() const;
        };

        // SWS_CORE_00340
        /**
         * \brief ara::core specific variant of std::promise class
         * 
         * \tparam T    the type of value 
         * \tparam E    the type of error
         */
        template<typename T, typename E = ErrorCode>
        class Promise
        {
            // SWS_CORE_00341
            /**
             * \brief Default constructor.
             * 
             * This function shall behave the same as the corresponding std::promise function.
             * 
             */
            Promise();

            // SWS_CORE_00342
            /**
             * \brief Move constructor.
             * This function shall behave the same as the corresponding std::promise function.
             * 
             * \param[in] other     the other instance
             */
            Promise(Promise &&other) noexcept;

            // SWS_CORE_00350
            /**
             * \brief Copy constructor shall be disabled.
             * 
             */
            Promise(Promise const &) = delete;

            // SWS_CORE_00349
            /**
             * \brief Destructor for Promise objects.
             * This function shall behave the same as the corresponding std::promise function.
             * 
             */
            ~Promise();

            // SWS_CORE_00343
            /**
             * \brief Move assignment.
             * This function shall behave the same as the corresponding std::promise function.
             * 
             * \param[in] other     the other instance
             * \return Promise&     *this
             */
            Promise& operator=(Promise &&other) noexcept;

            // SWS_CORE_00351
            /**
             * \brief Copy assignment operator shall be disabled.
             * 
             * \return Promise& 
             */
            Promise& operator=(Promise const &) = delete;

            // SWS_CORE_00352
            /**
             * \brief Swap the contents of this instance with another one’s.
             * This function shall behave the same as the corresponding std::promise function.
             * 
             * \param[in] other     the other instance
             */
            void swap(Promise &other) noexcept;

            // SWS_CORE_00344
            /**
             * \brief Return the associated Future.
             * 
             * The returned Future is set as soon as this Promise receives the result or an error. This method
             * must only be called once as it is not allowed to have multiple Futures per Promise.
             * 
             * \return Future<T, E>     a Future
             */
            Future<T, E> get_future();

            // SWS_CORE_00345
            /**
             * \brief Copy a value into the shared state and make the state ready.
             * 
             * This function shall behave the same as the corresponding std::promise function.
             * 
             * \param[in] value     the value to store
             */
            void set_value(T const &value);

            // SWS_CORE_00346
            /**
             * \brief Move a value into the shared state and make the state ready.
             * This function shall behave the same as the corresponding std::promise function.
             * 
             * \param[in] value     the value to store
             */
            void set_value(T &&value);

            // SWS_CORE_00353
            /**
             * \brief Move an error into the shared state and make the state ready.
             * 
             * \param[in] error     the error to store
             */
            void SetError(E &&error);

            // SWS_CORE_00354
            /**
             * \brief Copy an error into the shared state and make the state ready.
             * 
             * \param[in] error     the error to store
             */
            void SetError(E const &error);
        };


        // SWS_CORE_06340
        /**
         * \brief Specialization of class Promise for "void" values.
         * 
         * \tparam E    the type of error
         */
        template<typename E>
        class Promise<void, E> final
        {
            // SWS_CORE_06341
            /**
             * \brief Default constructor.
             * This function shall behave the same as the corresponding std::promise function.
             * 
             */
            Promise();

            // SWS_CORE_06342
            /**
             * \brief Move constructor.
             * This function shall behave the same as the corresponding std::promise function.
             * 
             * \param[in] other     the other instance
             */
            Promise(Promise &&other) noexcept;

            // SWS_CORE_06350
            /**
             * \brief Copy constructor shall be disabled.
             * 
             */
            Promise(Promise const &) = delete;

            // SWS_CORE_06349
            /**
             * \brief Destructor for Promise objects.
             * This function shall behave the same as the corresponding std::promise function.
             * 
             */
            ~Promise();

            // SWS_CORE_06343
            /**
             * \brief Move assignment.
             * This function shall behave the same as the corresponding std::promise function.
             * 
             * \param[in] other     the other instance
             * \return Promise&     *this
             */
            Promise& operator=(Promise &&other) noexcept;

            // SWS_CORE_06351
            /**
             * \brief Copy assignment operator shall be disabled.
             * 
             * \return Promise& 
             */
            Promise& operator=(Promise const &) = delete;

            // SWS_CORE_06352
            /**
             * \brief Swap the contents of this instance with another one’s.
             * This function shall behave the same as the corresponding std::promise function.
             * 
             * \param[in] other     the other instance
             */
            void swap(Promise &other) noexcept;

            // SWS_CORE_06344
            /**
             * \brief Return the associated Future.
             * 
             * The returned Future is set as soon as this Promise receives the result or an error. This method
             * must only be called once as it is not allowed to have multiple Futures per Promise.
             * 
             * \return Future<void, E>  a Future
             */
            Future<void, E> get_future();

            // SWS_CORE_06345
            /**
             * \brief Make the shared state ready.
             * 
             */
            void set_value();

            // SWS_CORE_06353
            /**
             * \brief Move an error into the shared state and make the state ready.
             * 
             * \param[in] error     the error to store
             */
            void SetError(E &&error);

            // SWS_CORE_06354
            /**
             * \brief Copy an error into the shared state and make the state ready.
             * 
             * \param[in] error     the error to store
             */
            void SetError(E const &error);
        };
        
    } // namespace core
    
} // namespace ara


#endif // ARA_CORE_FUTURE_H_
