/**
 * \file state_client.h
 * \author Vincent WANG (you@domain.com)
 * \brief 
 * \version 0.1
 * \date 2020-12-04
 * 
 * \copyright Copyright (c) 2020
 * 
 */
#ifndef ARA_EXEC_STATE_CLIENT_H
#define ARA_EXEC_STATE_CLIENT_H

// Base on the AUTOSAR_SWS_ExecutionManagement.pdf
// AUTOSAR AP R19-11

#include "ara/core/result.h"

namespace ara
{
    namespace exec
    {
        // SWS_EM_02263
        /**
         * Class representing Function Group defined in meta-model (ARXML).
         */
        class FunctionGroup
        {
            // SWS_EM_02264
            /**
             * \brief Pre construction method for FunctionGroup.
             * 
             * This method shall validate/verify meta-model path passed and perform any operation that could
             * fail and are expected to be performed in constructor.
             * 
             * \param[in] metaModelIdentifier   stringified meta model identifier (short name path)
             *                                  where path separator is ’/’.
             * 
             * \return Result<FunctionGroup::CtorToken>     a construction token from which an instance of
             *                                              FunctionGroup can be constructed, or ExecErrc
             *                                              error.
             * 
             * Thread-safe
             * 
             * \errors      ara::exec::ExecErrc::kMetaModelError    if metaModelIdentifier passed is incorrect (e.g.
             *                                                      FunctionGroupState identifier has been passed).
             *              ara::exec::ExecErrc::kGeneralError      if any other error occurs
             */
            static Result<FunctionGroup::CtorToken> Preconstruct(ara::core::StringView metaModelIdentifier) noexcept;

            // SWS_EM_02265
            /**
             * \brief Constructor that creates FunctionGroup instance.
             * 
             * \param[in] token     representing pre-constructed object.
             * 
             * \note Please note that token is destructed during object construction!
             */
            FunctionGroup(FunctionGroup::Ctortoken &&token) noexcept;

            // SWS_EM_02266
            /**
             * \brief Destructor of the FunctionGroup instance.
             * 
             */
            ~FunctionGroup() noexcept;

            // SWS_EM_02267
            /**
             * \brief eq operator to compare with other FunctionGroup instance.
             * 
             * \param[in] other     FunctionGroup instance to compare this one with.
             * 
             * \return true         in case both FunctionGroups are representing
             *                      exactly the same meta-model element,
             * \return false        otherwise.
             * 
             * Thread-safe
             */
            bool operator==(FunctionGroup const &other) const noexcept;

            // SWS_EM_02268
            /**
             * \brief uneq operator to compare with other FunctionGroup instance.
             * 
             * \param[in] other     FunctionGroup instance to compare this one with.
             * \return true         otherwise
             * \return false        in case both FunctionGroups are representing
             *                      exactly the same meta-model element
             * 
             * Thread-safe
             */
            bool operator!=(FunctionGroup const &other) const noexcept;
        };

        // SWS_EM_02269
        /**
         * \brief Class representing Function Group State defined in meta-model (ARXML).
         * 
         * \note Once created based on ARXML path, it’s internal value stay bounded to it for entire lifetime of
         *       an object.
         */
        class FunctionGroupState
        {
            // SWS_EM_02270
            /**
             * \brief Pre construction method for FunctionGroupState.
             * 
             * This method shall validate/verify meta-model path passed and perform any operation that could
             * fail and are expected to be performed in constructor.
             * 
             * \param[in] functionGroup         the Function Group instance the state shall be
             *                                  connected with.
             * \param[in] metaModelIdentifier   stringified meta model identifier (short name path)
             *                                  where path separator is ’/’.
             * 
             * \return ara::core::Result<FunctionGroupState::CtorToken>     a construction token from which an instance of
             *                                                              FunctionGroupState can be constructed, or Exec
             *                                                              ErrorDomain error.
             * 
             * Thread-safe
             */
            static Result<FunctionGroupState::CtorToken> Preconstruct(FunctionGroup const &functionGroup, ara::core::StringView metaModelIdentifier) noexcept;

            // SWS_EM_02271
            /**
             * \brief Constructor that creates FunctionGroupState instance
             * 
             * \param[in] token     representing pre-constructed object.
             * 
             * \note Please note that token is destructed during object construction!
             */
            FunctionGroupState(FunctionGroupState::CtorToken &&token) noexcept;

            // SWS_EM_02272
            /**
             * \brief Destructor of the FunctionGroupState instance
             * 
             */
            ~FunctionGroupState() noexcept;

            // SWS_EM_02273
            /**
             * \brief eq operator to compare with other FunctionGroupState instance.
             * 
             * \param[in] other     FunctionGroupState instance to compare this one with.
             * 
             * \return true         in case both FunctionGroupStates are
             *                      representing exactly the same meta-model element
             * \return false        otherwise
             * 
             * Thread-safe
             */
            bool operator==(FunctionGroupState const &other) const noexcept;

            // SWS_EM_02274
            /**
             * \brief uneq operator to compare with other FunctionGroupState instance.
             * 
             * \param[in] other     FunctionGroupState instance to compare this one with.
             * 
             * \return true         otherwise
             * \return false        in case both FunctionGroupStates are
             *                      representing exactly the same meta-model element
             * 
             * Thread-safe
             */
            bool operator!=(FunctionGroupState const &other) const noexcept;
        };

        // SWS_EM_02275
        /**
         * \brief Class representing connection to Execution Management that is used to request Function
         *        Group state transitions (or other operations).
         * 
         * \note StateClient opens communication channel to Execution Management (e.g. POSIX FIFO). Each
         *       Process that intends to perform state management, shall create an instance of this class and it
         *       shall have rights to use it.
         */
        class StateClient
        {
            // SWS_EM_02276
            /**
             * \brief Constructor that creates StateClient instance
             * 
             */
            StateClient() noexcept;

            // SWS_EM_02277
            /**
             * \brief Destructor of the StateClient instance
             * 
             */
            ~StateClient() noexcept;

            // SWS_EM_02278
            /**
             * \brief Method to request state transition for a single Function Group.
             * 
             * This method will request Execution Management to perform state transition and return
             * immediately. Returned ara::core::Future can be used to determine result of requested
             * transition.
             * 
             * \param[in] state     representing meta-model definition of a state inside
             *                      a specific Function Group. Execution Management
             *                      will perform state transition from the current state to
             *                      the state identified by this parameter.
             * 
             * \return ara::core::Future<void>  void if requested transition is successful, otherwise it
             *                                  returns ExecErrorDomain error.
             * 
             * \errors ara::exec::ExecErrc::kCancelled          if transition to the requested Function Group state
             *                                                  was cancelled by a newer request
             *         ara::exec::ExecErrc::kFailed             if transition to the requested Function Group state
             *                                                  failed
             *         ara::exec::ExecErrc::kInvalidArguments   if arguments passed doesn’t appear to be valid (e.g.
             *                                                  after a software update, given functionGroup doesn’t
             *                                                  exist anymore)
             *         ara::exec::ExecErrc::kCommunicationError if StateClient can’t communicate with Execution
             *                                                  Management (e.g. IPC link is down)
             *         ara::exec::ExecErrc::kGeneralError       if any other error occurs.
             * 
             * Thread-safe
             */
            Future<void> SetState(FunctionGroupState const &state) const noexcept;

            // SWS_EM_02279
            /**
             * \brief Method to retrieve result of Machine State initial transition to Startup state.
             * 
             * This method allows State Management to retrieve result of a transition specified by SWS_
             * EM_01023 and SWS_EM_02241. Please note that this transition happens once per machine
             * life cycle, thus result delivered by this method shall not change (unless machine is started
             * again).
             * 
             * \return Future<void>  void if requested transition is successful, otherwise it
             *                       returns ExecErrorDomain error.
             * 
             * \errors ara::exec::ExecErrc::kCancelled          if transition to the requested Function Group state
             *                                                  was cancelled by a newer request
             *         ara::exec::ExecErrc::kFailed             if transition to the requested Function Group state
             *                                                  failed
             *         ara::exec::ExecErrc::kCommunicationError if StateClient can’t communicate with Execution
             *                                                  Management (e.g. IPC link is down)
             *         ara::exec::ExecErrc::kGeneralError       if any other error occurs.
             * 
             * Thread-safe
             */
            Future<void> GetInitialMachineStateTransitionResult() const noexcept;

        };
    } // namespace exec
    
} // namespace ara


#endif // ARA_EXEC_STATE_CLIENT_H
