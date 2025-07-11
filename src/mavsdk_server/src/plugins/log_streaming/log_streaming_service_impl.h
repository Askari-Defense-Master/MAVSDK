// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/log_streaming/log_streaming.proto)

#include "log_streaming/log_streaming.grpc.pb.h"
#include "plugins/log_streaming/log_streaming.h"

#include "mavsdk.h"

#include "lazy_plugin.h"

#include "log.h"
#include <atomic>
#include <cmath>
#include <future>
#include <limits>
#include <memory>
#include <mutex>
#include <sstream>
#include <vector>

namespace mavsdk {
namespace mavsdk_server {


template<typename LogStreaming = LogStreaming, typename LazyPlugin = LazyPlugin<LogStreaming>>

class LogStreamingServiceImpl final : public rpc::log_streaming::LogStreamingService::Service {
public:

    LogStreamingServiceImpl(LazyPlugin& lazy_plugin) : _lazy_plugin(lazy_plugin) {}



    template<typename ResponseType>
    void fillResponseWithResult(ResponseType* response, mavsdk::LogStreaming::Result& result) const
    {
        auto rpc_result = translateToRpcResult(result);

        auto* rpc_log_streaming_result = new rpc::log_streaming::LogStreamingResult();
        rpc_log_streaming_result->set_result(rpc_result);
        std::stringstream ss;
        ss << result;
        rpc_log_streaming_result->set_result_str(ss.str());

        response->set_allocated_log_streaming_result(rpc_log_streaming_result);
    }




    static std::unique_ptr<rpc::log_streaming::LogStreamingRaw> translateToRpcLogStreamingRaw(const mavsdk::LogStreaming::LogStreamingRaw &log_streaming_raw)
    {
        auto rpc_obj = std::make_unique<rpc::log_streaming::LogStreamingRaw>();


            
        rpc_obj->set_data_base64(log_streaming_raw.data_base64);
            
        

        return rpc_obj;
    }

    static mavsdk::LogStreaming::LogStreamingRaw translateFromRpcLogStreamingRaw(const rpc::log_streaming::LogStreamingRaw& log_streaming_raw)
    {
        mavsdk::LogStreaming::LogStreamingRaw obj;


            
        obj.data_base64 = log_streaming_raw.data_base64();
            
        
        return obj;
    }




    static rpc::log_streaming::LogStreamingResult::Result translateToRpcResult(const mavsdk::LogStreaming::Result& result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case mavsdk::LogStreaming::Result::Success:
                return rpc::log_streaming::LogStreamingResult_Result_RESULT_SUCCESS;
            case mavsdk::LogStreaming::Result::NoSystem:
                return rpc::log_streaming::LogStreamingResult_Result_RESULT_NO_SYSTEM;
            case mavsdk::LogStreaming::Result::ConnectionError:
                return rpc::log_streaming::LogStreamingResult_Result_RESULT_CONNECTION_ERROR;
            case mavsdk::LogStreaming::Result::Busy:
                return rpc::log_streaming::LogStreamingResult_Result_RESULT_BUSY;
            case mavsdk::LogStreaming::Result::CommandDenied:
                return rpc::log_streaming::LogStreamingResult_Result_RESULT_COMMAND_DENIED;
            case mavsdk::LogStreaming::Result::Timeout:
                return rpc::log_streaming::LogStreamingResult_Result_RESULT_TIMEOUT;
            case mavsdk::LogStreaming::Result::Unsupported:
                return rpc::log_streaming::LogStreamingResult_Result_RESULT_UNSUPPORTED;
            case mavsdk::LogStreaming::Result::Unknown:
                return rpc::log_streaming::LogStreamingResult_Result_RESULT_UNKNOWN;
        }
    }

    static mavsdk::LogStreaming::Result translateFromRpcResult(const rpc::log_streaming::LogStreamingResult::Result result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case rpc::log_streaming::LogStreamingResult_Result_RESULT_SUCCESS:
                return mavsdk::LogStreaming::Result::Success;
            case rpc::log_streaming::LogStreamingResult_Result_RESULT_NO_SYSTEM:
                return mavsdk::LogStreaming::Result::NoSystem;
            case rpc::log_streaming::LogStreamingResult_Result_RESULT_CONNECTION_ERROR:
                return mavsdk::LogStreaming::Result::ConnectionError;
            case rpc::log_streaming::LogStreamingResult_Result_RESULT_BUSY:
                return mavsdk::LogStreaming::Result::Busy;
            case rpc::log_streaming::LogStreamingResult_Result_RESULT_COMMAND_DENIED:
                return mavsdk::LogStreaming::Result::CommandDenied;
            case rpc::log_streaming::LogStreamingResult_Result_RESULT_TIMEOUT:
                return mavsdk::LogStreaming::Result::Timeout;
            case rpc::log_streaming::LogStreamingResult_Result_RESULT_UNSUPPORTED:
                return mavsdk::LogStreaming::Result::Unsupported;
            case rpc::log_streaming::LogStreamingResult_Result_RESULT_UNKNOWN:
                return mavsdk::LogStreaming::Result::Unknown;
        }
    }




    grpc::Status StartLogStreaming(
        grpc::ServerContext* /* context */,
        const rpc::log_streaming::StartLogStreamingRequest* /* request */,
        rpc::log_streaming::StartLogStreamingResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            
            if (response != nullptr) {
                auto result = mavsdk::LogStreaming::Result::NoSystem;
                fillResponseWithResult(response, result);
            }
            
            return grpc::Status::OK;
        }

        
        auto result = _lazy_plugin.maybe_plugin()->start_log_streaming();
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status StopLogStreaming(
        grpc::ServerContext* /* context */,
        const rpc::log_streaming::StopLogStreamingRequest* /* request */,
        rpc::log_streaming::StopLogStreamingResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            
            if (response != nullptr) {
                auto result = mavsdk::LogStreaming::Result::NoSystem;
                fillResponseWithResult(response, result);
            }
            
            return grpc::Status::OK;
        }

        
        auto result = _lazy_plugin.maybe_plugin()->stop_log_streaming();
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status SubscribeLogStreamingRaw(grpc::ServerContext* /* context */, const mavsdk::rpc::log_streaming::SubscribeLogStreamingRawRequest* /* request */, grpc::ServerWriter<rpc::log_streaming::LogStreamingRawResponse>* writer) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            
            return grpc::Status::OK;
        }

        auto stream_closed_promise = std::make_shared<std::promise<void>>();
        auto stream_closed_future = stream_closed_promise->get_future();
        register_stream_stop_promise(stream_closed_promise);

        auto is_finished = std::make_shared<bool>(false);
        auto subscribe_mutex = std::make_shared<std::mutex>();

        const mavsdk::LogStreaming::LogStreamingRawHandle handle = _lazy_plugin.maybe_plugin()->subscribe_log_streaming_raw(
            [this, &writer, &stream_closed_promise, is_finished, subscribe_mutex, &handle](const mavsdk::LogStreaming::LogStreamingRaw log_streaming_raw) {

            rpc::log_streaming::LogStreamingRawResponse rpc_response;
        
            rpc_response.set_allocated_logging_raw(translateToRpcLogStreamingRaw(log_streaming_raw).release());
        

        

            std::unique_lock<std::mutex> lock(*subscribe_mutex);
            if (!*is_finished && !writer->Write(rpc_response)) {
                
                _lazy_plugin.maybe_plugin()->unsubscribe_log_streaming_raw(handle);
                
                *is_finished = true;
                unregister_stream_stop_promise(stream_closed_promise);
                stream_closed_promise->set_value();
            }
        });

        stream_closed_future.wait();
        std::unique_lock<std::mutex> lock(*subscribe_mutex);
        *is_finished = true;

        return grpc::Status::OK;
    }


    void stop() {
        _stopped.store(true);
        std::lock_guard<std::mutex> lock(_stream_stop_mutex);
        for (auto& prom : _stream_stop_promises) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        }
    }

private:
    void register_stream_stop_promise(std::weak_ptr<std::promise<void>> prom) {
        // If we have already stopped, set promise immediately and don't add it to list.
        if (_stopped.load()) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        } else {
            std::lock_guard<std::mutex> lock(_stream_stop_mutex);
            _stream_stop_promises.push_back(prom);
        }
    }

    void unregister_stream_stop_promise(std::shared_ptr<std::promise<void>> prom) {
        std::lock_guard<std::mutex> lock(_stream_stop_mutex);
        for (auto it = _stream_stop_promises.begin(); it != _stream_stop_promises.end(); /* ++it */) {
            if (it->lock() == prom) {
                it = _stream_stop_promises.erase(it);
            } else {
                ++it;
            }
        }
    }


    LazyPlugin& _lazy_plugin;

    std::atomic<bool> _stopped{false};
    std::mutex _stream_stop_mutex{};
    std::vector<std::weak_ptr<std::promise<void>>> _stream_stop_promises {};
};

} // namespace mavsdk_server
} // namespace mavsdk