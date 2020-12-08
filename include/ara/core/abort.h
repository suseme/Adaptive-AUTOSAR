/**
 * \file abort.h
 * \author Vincent WANG (you@domain.com)
 * \brief 
 * \version 0.1
 * \date 2020-12-08
 * 
 * \copyright Copyright (c) 2020
 * 
 */
#ifndef ARA_CORE_ABORT_H_
#define ARA_CORE_ABORT_H_

namespace ara
{
    namespace core
    {
        // SWS_CORE_00050
        /**
         * \brief The type of a handler for SetAbortHandler().
         * 
         */
        using AbortHandler = void (*)() noexcept;

        // SWS_CORE_00051
        /**
         * \brief Set a custom global Abort handler function and return the previously installed one.
         * 
         * By setting nullptr, the implementation may restore the default handler instead.
         * 
         * This function can be called from multiple threads simultaneously; these calls are performed in
         * an implementation-defined sequence.
         * 
         * \param[in] handler   a custom Abort handler (or nullptr)
         * \return AbortHandler the previously installed Abort handler (or nullptr if none was installed)
         */
        AbortHandler SetAbortHandler(AbortHandler handler) noexcept;

        // SWS_CORE_00052
        /**
         * \brief Terminate the current process abnormally.
         * 
         * Before terminating, a log message with FATAL severity is being output, which includes the text
         * given as argument to this function.
         * 
         * This function will never return to its caller. The stack is not unwound: destructors of variables
         * with automatic storage duration are not called.
         * 
         * An application can add exactly one own "hook" into this mechanism by calling the function Set
         * AbortHandler(). If such an Abort handler has been installed, it is called in turn when Abort() is
         * invoked, but after the log message has been output. If there is no custom Abort handler, or if
         * there is one and it returns, then the invocation of this function will terminate the process via
         * std::abort().
         * 
         * Any call of this function that is performed while another call is already in progress will block the
         * calling thread.
         * 
         * The text argument is expected to point to a null-terminated string with static storage duration.
         * 
         * Note: The type of the text argument is a raw pointer (instead of a more "modern" type such as
         * StringView) in order to increase the chances that the function call succeeds even in situations
         * when e.g. the stack has been corrupted.
         * 
         * \param[in] text  a custom text to include in the log message being output
         */
        void Abort(char const *text) noexcept;
    } // namespace core
    
} // namespace ara


#endif // ARA_CORE_ABORT_H_
