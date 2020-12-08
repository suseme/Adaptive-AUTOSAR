/**
 * \file key_value_storage.h
 * \author Vincent WANG (you@domain.com)
 * \brief 
 * \version 0.1
 * \date 2020-12-08
 * 
 * \copyright Copyright (c) 2020
 * 
 */
#ifndef ARA_PER_KEY_VALUE_STORAGE_H_
#define ARA_PER_KEY_VALUE_STORAGE_H_

#include "ara/core/result.h"

namespace ara
{
    namespace per
    {
        //SWS_PER_00052
        /**
         * \brief Opens a key-value storage.
         * 
         * \param[in] kvs   The shortName path of a PortPrototype typed by a
         *                  PersistencyKeyValueDatabaseInterface.
         * \return ara::core::Result<SharedHandle<KeyValueStorage>>     A Result, containing a SharedHandle, or one of the
         *                                                              errors defined for Persistency in PerErrc.
         * \note 
         * \thread safety reentrant
         */
        ara::core::Result<SharedHandle<KeyValueStorage>> OpenKeyValueStorage(ara::core::InstanceSpecifier kvs) noexcept;

        // SWS_PER_00333
        /**
         * \brief Recover an instance of KeyValueStorage.
         * 
         * This method allows to recover a key-value storage when the redundancy checks fail. It will fail
         * with a kResourceBusyError when the key-value storage is currently open.
         * 
         * This method does a best-effort recovery of all keys. After recovery, keys might show outdated
         * or initial value, or might be lost.
         * 
         * \param[in] kvs   The shortName path of a PortPrototype typed by a
         *                  PersistencyKeyValueDatabaseInterface.
         * \return ara::core::Result<void>  A Result, being either empty or containing one of
         *                                  the errors defined for Persistency in PerErrc.
         * \note 
         * \thread safety reentrant
         */
        ara::core::Result<void> RecoverKeyValueStorage(ara::core::InstanceSpecifier kvs) noexcept;

        // SWS_PER_0033
        /**
         * \brief Reset an instance of KeyValueStorage to the initial state.
         * 
         * This method allows to reset a key-value storage to the initial state, containing only keys which
         * were deployed from the manifest, with their initial values. It will fail with a kResourceBusyError
         * when the key-value storage is currently open.
         * 
         * \param[in] kvs   The shortName path of a PortPrototype typed by a
         *                  PersistencyKeyValueDatabaseInterface.
         * \return ara::core::Result<void>  A Result, being either empty or containing one of
         *                                  the errors defined for Persistency in PerErrc.
         * \note 
         * \thread safety reentrant
         */
        ara::core::Result<void> ResetKeyValueStorage(ara::core::InstanceSpecifier kvs) noexcept;

        // SWS_PER_00405
        /**
         * \brief Returns the space in bytes currently occupied by a Key-Value Storage.
         * 
         * \param[in] kvs   The shortName path of a PortPrototype typed by a
         *                  PersistencyKeyValueDatabaseInterface.
         * \return ara::core::Result<uint64_t>  A Result, containing the occupied space in bytes, or
         *                                      one of the errors defined for Persistency in PerErrc.
         * \note 
         * \thread safety reentrant
         */
        ara::core::Result<uint64_t> GetCurrentKeyValueStorageSize(ara::core::InstanceSpecifier kvs) noexcept;
        

        // SWS_PER_00339
        /**
         * \brief The key-value storage contains a set of keys with associated values. .
         * 
         * \note 
         */
        class KeyValueStorage
        {
            // SWS_PER_00322
            /**
             * \brief Move constructor for KeyValueStorage.
             * 
             * \param[in] kvs   The KeyValueStorage object to be moved.
             * \note 
             * \thread safety reentrant
             */
            KeyValueStorage(KeyValueStorage &&kvs) noexcept;

            // SWS_PER_00324
            /**
             * \brief The copy constructor for KeyValueStorage shall not be used.
             * 
             * \note 
             */
            KeyValueStorage(const KeyValueStorage &) = delete;

            // SWS_PER_00323
            /**
             * \brief Move assignment operator for KeyValueStorage.
             * 
             * \param[in] kvs   The KeyValueStorage object to be moved.
             * \return KeyValueStorage&     The moved KeyValueStorage object.
             * \note 
             * \thread safety reentrant
             */
            KeyValueStorage& operator=(KeyValueStorage &&kvs) & noexcept;

            // SWS_PER_00325
            /**
             * \brief The copy assignment operator for KeyValueStorage shall not be used.
             * 
             * \return KeyValueStorage& 
             * \note 
             */
            KeyValueStorage& operator=(const KeyValueStorage &) = delete;

            // SWS_PER_00050
            /**
             * \brief Destructor for KeyValueStorage.
             * 
             * \note 
             * \thread safety no
             */
            ~KeyValueStorage() noexcept;

            // SWS_PER_00042
            /**
             * \brief Returns a list of all currently available keys of the KeyValueStorage.
             * 
             * \return ara::core::Result<ara::core::Vector<ara::core::String>>  A Result, containing a list of available keys, or one of
             *                                                                  the errors defined for Persistency in PerErrc.
             * \note 
             * \thread safety reentrant
             */
            ara::core::Result<ara::core::Vector<ara::core::String>> GetAllKeys() const noexcept;

            // SWS_PER_00043
            /**
             * \brief Checks if a key exists in the KeyValueStorage.
             * 
             * \param[in] key   The key that shall be checked.
             * \return ara::core::Result<bool>  A Result, containing true if the key could be located
             *                                  or false if it couldn’t, or one of the errors defined for
             *                                  Persistency in PerErrc.
             * \note 
             * \thread safety reentrant
             */
            ara::core::Result<bool> HasKey(ara::core::StringView key) const noexcept;

            // SWS_PER_00332
            /**
             * \brief Returns the value assigned to a key of the KeyValueStorage.
             * 
             * \tparam T    The type of the value that shall be retrieved.
             * \param[in] key   The key to look up.
             * \return ara::core::Result<T>     A Result, being either the retrieved value or
             *                                  containing one of the errors defined for Persistency
             *                                  in PerErrc.
             * \note 
             * \thread safety reentrant
             */
            template<class T>
            ara::core::Result<T> GetValue(ara::core::StringView key) const noexcept;

            // SWS_PER_00046
            /**
             * \brief Stores a key in the KeyValueStorage. If a value already exists, it is overwritten, independent of
             *  the stored data type.
             * 
             * \tparam T    The type of the value that shall be set.
             * \param[in] key   The key to assign the value to. 
             * \param[in] value The value to store.
             * \return ara::core::Result<void>  A Result, being empty or containing one of the
             *                                  errors defined for Persistency in PerErrc.
             * \note 
             * \thread safety reentrant
             */
            template<class T>
            ara::core::Result<void> SetValue(ara::core::StringView key, const T &value) noexcept;

            // SWS_PER_00047
            /**
             * \brief Removes a key and the associated value from the KeyValueStorage.
             * 
             * \param[in] key   The key to be removed.
             * \return ara::core::Result<void>  A Result, being empty or containing one of the
             *                                  errors defined for Persistency in PerErrc.
             * \note 
             * \thread safety reentrant
             */
            ara::core::Result<void> RemoveKey(ara::core::StringView key) noexcept;

            // SWS_PER_00048
            /**
             * \brief Removes all keys and associated values from the KeyValueStorage.
             * 
             * \return ara::core::Result<void>  A Result, being empty or containing one of the
             *                                  errors defined for Persistency in PerErrc.
             * \note 
             * \thread safety reentrant
             */
            ara::core::Result<void> RemoveAllKey() noexcept;

            // SWS_PER_00049
            /**
             * \brief Triggers flushing of key-value pairs to the physical storage of the KeyValueStorage.
             * 
             * \return ara::core::Result<void>  A Result, being either empty or containing one of
             *                                  the errors defined for Persistency in PerErrc.
             * \note 
             * \thread safety reentrant
             */
            ara::core::Result<void> SyncToStorage() noexcept;

            // SWS_PER_00365
            /**
             * \brief Removes all pending changes to the KeyValueStorage since the last call to SyncToStorage() or
             * since the KeyValueStorage was opened using OpenKeyValueStorage().
             * 
             * \return ara::core::Result<void>  A Result, being either empty or containing one of
             *                                  the errors defined for Persistency in PerErrc.
             * \note 
             * \thread safety reentrant
             */
            ara::core::Result<void> DiscardPendingChanges() noexcept;

            // SWS_PER_00335
            /**
             * \brief Recover the whole file storage, including all files.
             * 
             * This method allows to recover a file storage when the redundancy checks fail. It will fail with a k
             * ResourceBusyError when the file storage is currently open.
             * 
             * This method does a best-effort recovery of all files. After recovery, files might show outdated or
             * initial content, or might be lost.
             * 
             * \param[in] fs    The shortName path of a PortPrototype typed by a
             *                  PersistencyFileProxyInterface.
             * \return ara::core::Result<void>  A Result, being either empty or containing one of
             *                                  the errors defined for Persistency in PerErrc.
             * \note 
             * \thread safety reentrant
             */
            ara::core::Result<void> RecoverAllFiles(ara::core::InstanceSpecifier fs) noexcept;

            // SWS_PER_00336
            /**
             * \brief 
             * 
             * \param[in] fs 
             * \return ara::core::Result<void> 
             * \note 
             * \thread safety reentrant
             */
            ara::core::Result<void> ResetAllFiles(ara::core::InstanceSpecifier fs) noexcept;
        };
    } // namespace per
    
} // namespace ara


#endif // ARA_PER_KEY_VALUE_STORAGE_H_
