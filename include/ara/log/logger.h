/**
 * \file logger.h
 * \author Vincent WANG (you@domain.com)
 * \brief 
 * \version 0.1
 * \date 2020-12-08
 * 
 * \copyright Copyright (c) 2020
 * 
 */
#ifndef ARA_LOG_LOGGER_H_
#define ARA_LOG_LOGGER_H_

#include "ara/log/logstream.h"

namespace ara
{
    namespace log
    {
        class Logger
        {
            // SWS_LOG_00064
            /**
             * \brief Creates a LogStream object.
             *  Returned object will accept arguments via the insert stream operator "@c <<".
             * 
             * \return LogStream LogStream object of Fatal severity.
             * 
             * \note In the normal usage scenario, the object’s life time of the created LogStream is scoped within
             *  one statement (ends with ; after last passed argument). If one wants to extend the LogStream
             *  object’s life time, the object might be assigned to a named variable.
             * 
             * \thread safety
             */
            LogStream LogFatal() noexcept;

            // SWS_LOG_00065
            /**
             * \brief Same as Logger::LogFatal().
             * 
             * \return LogStream    LogStream object of Error severity.
             * \note 
             * \thread safety
             */
            LogStream LogError() noexcept;

            // SWS_LOG_00066
            /**
             * \brief Same as Logger::LogFatal().
             * 
             * \return LogStream    LogStream object of Warn severity.
             * \note 
             * \thread safety
             */
            LogStream LogWarn() noexcept;

            // SWS_LOG_00067
            /**
             * \brief Same as Logger::LogFatal().
             * 
             * \return LogStream    LogStream object of Info severity.
             * \note 
             * \thread safety
             */
            LogStream LogInfo() noexcept;

            // SWS_LOG_00068
            /**
             * \brief Same as Logger::LogFatal().
             * 
             * \return LogStream    LogStream object of Debug severity.
             * \note 
             * \thread safety
             */
            LogStream LogDebug() noexcept;

            // SWS_LOG_00069
            /**
             * \brief Same as Logger::LogFatal().
             * 
             * \return LogStream    LogStream object of Verbose severity.
             * \note 
             * \thread safety
             */
            LogStream LogVerbose() noexcept;

            // SWS_LOG_00070
            /**
             * \brief Check current configured log reporting level.
             * 
             * Applications may want to check the actual configured reporting log level of certain loggers
             * before doing log data preparation that is runtime intensive.
             * 
             * \param[in] logLevel  The to be checked log level.
             * 
             * \return true     if desired log level satisfies the configured
             *                  reporting level.
             * \return false 
             * \note 
             * \thread safety reentrant
             */
            bool IsEnabled(LogLevel logLevel) const noexcept;
        };
    } // namespace log
    
} // namespace ara


#endif // ARA_LOG_LOGGER_H_
