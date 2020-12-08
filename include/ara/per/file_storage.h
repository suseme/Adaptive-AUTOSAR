/**
 * \file file_storage.h
 * \author Vincent WANG (you@domain.com)
 * \brief 
 * \version 0.1
 * \date 2020-12-08
 * 
 * \copyright Copyright (c) 2020
 * 
 */
#ifndef ARA_PER_FILE_STORAGE_H_
#define ARA_PER_FILE_STORAGE_H_

#include "ara/core/result.h"

namespace ara
{
    namespace per
    {
        // SWS_PER_00116
        /**
         * \brief 
         * 
         * \param[in] fs    The shortName path of a PortPrototype typed by a
         *                  PersistencyFileProxyInterface.
         * \return ara::core::Result<SharedHandle<FileStorage>>     A Result, containing a SharedHandle, or one of the
         *                                                          errors defined for Persistency in PerErrc.
         * \note 
         * \thread safety reentrant
         */
        ara::core::Result<SharedHandle<FileStorage>> OpenFileStorage(ara::core::InstanceSpecifier fs) noexcept;
    } // namespace per
    
} // namespace ara


#endif // ARA_PER_FILE_STORAGE_H_
