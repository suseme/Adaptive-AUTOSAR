/**
 * \file initialization.h
 * \author Vincent WANG (you@domain.com)
 * \brief 
 * \version 0.1
 * \date 2020-12-08
 * 
 * \copyright Copyright (c) 2020
 * 
 */
#ifndef ARA_CORE_INITIALIZATION_H_
#define ARA_CORE_INITIALIZATION_H_

#include "ara/core/result.h"

namespace ara
{
    namespace core
    {
        // SWS_CORE_10001
        /**
         * \brief Initializes data structures and threads of the AUTOSAR Adaptive Runtime for Applications.
         * 
         * Prior to this call, no interaction with the ARA is possible. This call must be made inside of
         * main(), i.e., in a place where it is guaranteed that static memory initialization has completed.
         * Depending on the individual functional cluster specification, the calling application may have to
         * provide additional configuration data (e.g., set an Application ID for Logging) or make additional
         * initailization calls (e.g., start a FindService in ara::com) before other API calls to the respective
         * functional cluster can be made. Such calls must be made after the call to Initialize(). Calls to
         * ARA APIs made before static initialization has completed lead to undefinded behavior. Calls
         * made after static initialization has completed but before Initialize() was called will be rejected by
         * the functional cluster implementation with an error or, if no error to be reported is defined, lead
         * to undefined behavior.
         * 
         * \return Result<void>     A Result object that indicates whether the
         *                          AUTOSAR Adaptive Runtime for Applications was
         *                          successfully initialized. Note that this is the only way
         *                          for the ARA to report an error that is guaranteed to
         *                          be available, e.g., in case ara::log failed to correctly
         *                          initialize. The user is not expected to be able to
         *                          recover from such an error. However, the user may
         *                          have a project-specific way of recording errors
         *                          during initialization without ara::log.
         */
        Result<void> Initialize();

        // SWS_CORE_10002
        /**
         * \brief Destroy all data structures and threads of the AUTOSAR Adaptive Runtime for Applications.
         * 
         * After this call, no interaction with the ARA is possible. This call must be made inside of main(),
         * i.e., in a place where it is guaranteed that the static initialization has completed and destruciton
         * of statically initialized data has not yet started. Calls made to ARA APIs after a call to
         * ara::core::Deinitialize() but before destruction of statically initialized data will be rejected with an
         * error or, if no error is defined, lead to undefined behavior. Calls made to ARA APIs after the
         * destruction of statically initialized data will lead to undefined behavior.
         * 
         * \return Result<void>     A Result object that indicates whether the ARA was
         *                          successfully destroyed. Typical error cases to be
         *                          reported here are that the user is still holding some
         *                          resource inside the ARA. Note that this Result is the
         *                          only way for the ARA to report an error that is
         *                          guaranteed to be available, e.g., in case ara::log has
         *                          already been deinitialized. The user is not expected
         *                          to be able to recover from such an error. However,
         *                          the user may have a project-specific way of
         *                          recording errors during deinitialization without
         *                          ara::log.
         * 
         */
        Result<void> Deinitialize();
    } // namespace core
    
} // namespace ara


#endif // ARA_CORE_INITIALIZATION_H_
