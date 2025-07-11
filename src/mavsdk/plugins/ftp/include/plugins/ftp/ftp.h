// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/main/protos/ftp/ftp.proto)

#pragma once

#include <array>
#include <cmath>
#include <functional>
#include <limits>
#include <memory>
#include <string>
#include <utility>
#include <vector>


#include "plugin_base.h"

#include "handle.h"

namespace mavsdk {


class System;class FtpImpl;

/**
 * @brief Implements file transfer functionality using MAVLink FTP.
 */
class Ftp : public PluginBase {
public:

    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto ftp = Ftp(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit Ftp(System& system); // deprecated

    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto ftp = Ftp(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit Ftp(std::shared_ptr<System> system); // new


    /**
     * @brief Destructor (internal use only).
     */
    ~Ftp() override;





    /**
     * @brief The output of a directory list
     */
    struct ListDirectoryData {
        
        std::vector<std::string> dirs{}; /**< @brief The found directories. */
        std::vector<std::string> files{}; /**< @brief The found files. */
    };

    /**
     * @brief Equal operator to compare two `Ftp::ListDirectoryData` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Ftp::ListDirectoryData& lhs, const Ftp::ListDirectoryData& rhs);

    /**
     * @brief Stream operator to print information about a `Ftp::ListDirectoryData`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Ftp::ListDirectoryData const& list_directory_data);




    /**
     * @brief Progress data type for file transfer.
     */
    struct ProgressData {
        
        uint32_t bytes_transferred{}; /**< @brief The number of bytes already transferred. */
        uint32_t total_bytes{}; /**< @brief The total bytes to transfer. */
    };

    /**
     * @brief Equal operator to compare two `Ftp::ProgressData` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Ftp::ProgressData& lhs, const Ftp::ProgressData& rhs);

    /**
     * @brief Stream operator to print information about a `Ftp::ProgressData`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Ftp::ProgressData const& progress_data);





    /**
     * @brief Possible results returned for FTP commands
     */
    enum class Result {
        Unknown, /**< @brief Unknown result. */
        Success, /**< @brief Success. */
        Next, /**< @brief Intermediate message showing progress. */
        Timeout, /**< @brief Timeout. */
        Busy, /**< @brief Operation is already in progress. */
        FileIoError, /**< @brief File IO operation error. */
        FileExists, /**< @brief File exists already. */
        FileDoesNotExist, /**< @brief File does not exist. */
        FileProtected, /**< @brief File is write protected. */
        InvalidParameter, /**< @brief Invalid parameter. */
        Unsupported, /**< @brief Unsupported command. */
        ProtocolError, /**< @brief General protocol error. */
        NoSystem, /**< @brief No system connected. */
    };

    /**
     * @brief Stream operator to print information about a `Ftp::Result`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Ftp::Result const& result);



    /**
     * @brief Callback type for asynchronous Ftp calls.
     */
    using ResultCallback = std::function<void(Result)>;




        
    /**
     * @brief Callback type for download_async.
     */
    using DownloadCallback = std::function<void(Result, ProgressData)>;

    /**
     * @brief Downloads a file to local directory.
     */
    void download_async(std::string remote_file_path, std::string local_dir, bool use_burst, const DownloadCallback& callback);

        






        
    /**
     * @brief Callback type for upload_async.
     */
    using UploadCallback = std::function<void(Result, ProgressData)>;

    /**
     * @brief Uploads local file to remote directory.
     */
    void upload_async(std::string local_file_path, std::string remote_dir, const UploadCallback& callback);

        






    /**
    * @brief Callback type for list_directory_async.
    */
    using ListDirectoryCallback = std::function<void(Result, ListDirectoryData)>;

    /**
     * @brief Lists items from a remote directory.
     *
     * This function is non-blocking. See 'list_directory' for the blocking counterpart.
     */
    void list_directory_async(std::string remote_dir, const ListDirectoryCallback callback);



    /**
     * @brief Lists items from a remote directory.
     *
     * This function is blocking. See 'list_directory_async' for the non-blocking counterpart.
     *
     * @return Result of request.
     */
    std::pair<Result, Ftp::ListDirectoryData> list_directory(std::string remote_dir) const;




    /**
     * @brief Creates a remote directory.
     *
     * This function is non-blocking. See 'create_directory' for the blocking counterpart.
     */
    void create_directory_async(std::string remote_dir, const ResultCallback callback);



    /**
     * @brief Creates a remote directory.
     *
     * This function is blocking. See 'create_directory_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result create_directory(std::string remote_dir) const;




    /**
     * @brief Removes a remote directory.
     *
     * This function is non-blocking. See 'remove_directory' for the blocking counterpart.
     */
    void remove_directory_async(std::string remote_dir, const ResultCallback callback);



    /**
     * @brief Removes a remote directory.
     *
     * This function is blocking. See 'remove_directory_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result remove_directory(std::string remote_dir) const;




    /**
     * @brief Removes a remote file.
     *
     * This function is non-blocking. See 'remove_file' for the blocking counterpart.
     */
    void remove_file_async(std::string remote_file_path, const ResultCallback callback);



    /**
     * @brief Removes a remote file.
     *
     * This function is blocking. See 'remove_file_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result remove_file(std::string remote_file_path) const;




    /**
     * @brief Renames a remote file or remote directory.
     *
     * This function is non-blocking. See 'rename' for the blocking counterpart.
     */
    void rename_async(std::string remote_from_path, std::string remote_to_path, const ResultCallback callback);



    /**
     * @brief Renames a remote file or remote directory.
     *
     * This function is blocking. See 'rename_async' for the non-blocking counterpart.
     *
     
     * @return Result of request.
     
     */
    Result rename(std::string remote_from_path, std::string remote_to_path) const;




    /**
    * @brief Callback type for are_files_identical_async.
    */
    using AreFilesIdenticalCallback = std::function<void(Result, bool)>;

    /**
     * @brief Compares a local file to a remote file using a CRC32 checksum.
     *
     * This function is non-blocking. See 'are_files_identical' for the blocking counterpart.
     */
    void are_files_identical_async(std::string local_file_path, std::string remote_file_path, const AreFilesIdenticalCallback callback);



    /**
     * @brief Compares a local file to a remote file using a CRC32 checksum.
     *
     * This function is blocking. See 'are_files_identical_async' for the non-blocking counterpart.
     *
     * @return Result of request.
     */
    std::pair<Result, bool> are_files_identical(std::string local_file_path, std::string remote_file_path) const;






    /**
     * @brief Set target component ID. By default it is the autopilot.
     *
     * This function is blocking.
     *
     
     * @return Result of request.
     
     */
    Result set_target_compid(uint32_t compid) const;




    /**
     * @brief Copy constructor.
     */
    Ftp(const Ftp& other);

    /**
     * @brief Equality operator (object is not copyable).
     */
    const Ftp& operator=(const Ftp&) = delete;

private:
    /** @private Underlying implementation, set at instantiation */
    std::unique_ptr<FtpImpl> _impl;
};

} // namespace mavsdk