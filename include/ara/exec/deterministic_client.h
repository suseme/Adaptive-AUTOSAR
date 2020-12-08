/**
 * \file deterministic_client.h
 * \author Vincent WANG (you@domain.com)
 * \brief 
 * \version 0.1
 * \date 2020-12-04
 * 
 * \copyright Copyright (c) 2020
 * 
 */
#ifndef ARA_EXEC_DETERMINISTIC_CLIENT_H_
#define ARA_EXEC_DETERMINISTIC_CLIENT_H_

// Base on the AUTOSAR_SWS_ExecutionManagement.pdf
// AUTOSAR AP R19-11

#include <cstdint>

namespace ara
{
    namespace exec
    {
        // SWS_EM_02201
        /**
         * Defines the return codes for WaitForNextActivation operations. Scoped Enumeration of uint8_t .
         */
        enum class ActivationReturnType : uint8_t
        {
            kRegisterServices = 0,  // application shall register communication
                                    // services(this must be the only occasion for
                                    // performing service registering)
            kServiceDiscovery = 1,  // application shall do communication service
                                    // discovery (this must be the only occasion for
                                    // performing service discovery)
            kInit = 2,              // application shall initialize its internal data structures
                                    // (once)
            kRun = 3,               // application shall perform its normal operation
            kTerminater = 4,        // application shall terminate

        };

        // SWS_EM_02202
        /**
         * Defines the return codes for "get activation timestamp" operations. Scoped Enumeration of uint8_t .
         */
        enum class ActivationTimeStampReturnType : uint8_t
        {
            kSuccess = 0,
            kNotAvailable = 1,
        };

        // SWS_EM_02210
        /**
         * Class to implement operations on Deterministic Client .
         */
        class DeterministicClient
        {
            // SWS_EM_02211
            /**
             * Constructor for DeterministicClient which opens the Execution Management communication
             * channel (e.g. POSIX FIFO) to access a wait point for cyclic execution, a worker pool,
             * deterministic random numbers and time stamps .
             */
            DeterministicClient() const noexcept;

            // SWS_EM_02215
            /**
             * Destructor of the Deterministic Client instance .
             */
            ~DeterministicClient() const noexcept;

            // SWS_EM_02216
            /**
             * Blocks and returns with a process control value when the next activation is triggered by the
             * Runtime.
             * 
             * \return      ActivationReturnType.
             */
            ActivationReturnType WaitForNextActivation() const noexcept;

            // SWS_EM_02220
            /**
             * Uses a worker pool to call a method Worker::workerRunnable (...) for every element of the
             * container. The sequential iteration is guaranteed by using the container++ operator. The API
             * guarantees that no other iteration scheme is used .
             * 
             * \param[in]   runnableObj     Object that provides a method called
             *                              worker-Runnable (...), which will be called on every
             *                              container element
             * \param[in]   container       C++ container which supports a standard iterator
             *                              interface with - begin() - end() - operator*()
             *                              operator++
             * 
             * \return void
             */
            void RunWorkerPool(Worker &runnableObj, Container &container) const noexcept;

            // SWS_EM_02225
            /**
             * This returns ‘Deterministic’ random numbers. Deterministic’ means, that the returned random
             * numbers are identical within redundant DeterministicClient::WaitForNextActivation() cycles,
             * which are used within redundantly executed Process .
             * 
             * \return uint64_t     uint64_t 64 bit uniform distributed pseudo random
             *                      number
             */
            uint64_t GetRandom() const noexcept;

            // SWS_EM_02230
            /**
             * This provides the timestamp that represents the point in time when the activation was triggered
             * by \DeterministicClient::WaitForNextActivation() with return value kRun. Subsequent calls
             * within an activation cycle will always provide the same value. The same value will also be
             * provided within redundantly executed Processes .
             * 
             * \param       TimeStamp   DIRECTION NOT DEFINED
             * 
             * \return      ActivationTimeStampReturnType
             */
            ActivationTimeStampReturnType GetActivationTime(TimeStamp) const noexcept;

            // SWS_EM_02235
            /**
             * This provides the timestamp that represents the point in time when the next activation will be
             * triggered by \ARApiRef{DeterministicClient::WaitForNextActivation}() with return value kRun.
             * Subsequent calls within an activation cycle will always provide the same value. The same value
             * will also be provided within redundantly executed RefES{Process} .
             * 
             * \param       TimeStamp   DIRECTION NOT DEFINED
             * 
             * \return      ActivationTimeStampReturnType
             */
            ActivationTimeStampReturnType GetNextActivationTime(TimeStamp) const noexcept;
        };
    } // namespace exec
    
} // namespace ara

#endif // ARA_EXEC_DETERMINISTIC_CLIENT_H_
