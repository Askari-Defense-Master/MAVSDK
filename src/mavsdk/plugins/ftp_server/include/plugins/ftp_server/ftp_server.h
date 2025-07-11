// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/main/protos/ftp_server/ftp_server.proto)

#pragma once

#include <array>
#include <cmath>
#include <functional>
#include <limits>
#include <memory>
#include <string>
#include <utility>
#include <vector>


#include "server_plugin_base.h"

#include "handle.h"

namespace mavsdk {


class ServerComponent;
class FtpServerImpl;

/**
 * @brief Provide files or directories to transfer.
 */
class FtpServer : public ServerPluginBase {
public:

    /**
     * @brief Constructor. Creates the plugin for a ServerComponent instance.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto ftp_server = FtpServer(server_component);
     *     ```
     *
     * @param server_component The ServerComponent instance associated with this server plugin.
     */
    explicit FtpServer(std::shared_ptr<ServerComponent> server_component);


    /**
     * @brief Destructor (internal use only).
     */
    ~FtpServer() override;






    /**
     * @brief Possible results returned for FTP server requests.
     */
    enum class Result {
        Unknown, /**< @brief Unknown result. */
        Success, /**< @brief Request succeeded. */
        DoesNotExist, /**< @brief Directory does not exist. */
        Busy, /**< @brief Operations in progress. */
    };

    /**
     * @brief Stream operator to print information about a `FtpServer::Result`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, FtpServer::Result const& result);



    /**
     * @brief Callback type for asynchronous FtpServer calls.
     */
    using ResultCallback = std::function<void(Result)>;






    /**
     * @brief Set root directory.
     *
     * This is the directory that can then be accessed by a client.
     * The directory needs to exist when this is called.
     * The permissions are the same as the file permission for the user running the server.
     * The root directory can't be changed while an FTP process is in progress.
     *
     * This function is blocking.
     *
     
     * @return Result of request.
     
     */
    Result set_root_dir(std::string path) const;




    /**
     * @brief Copy constructor.
     */
    FtpServer(const FtpServer& other);

    /**
     * @brief Equality operator (object is not copyable).
     */
    const FtpServer& operator=(const FtpServer&) = delete;

private:
    /** @private Underlying implementation, set at instantiation */
    std::unique_ptr<FtpServerImpl> _impl;
};

} // namespace mavsdk