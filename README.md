# Introduction
The point of this tutorial is not about completely understanding the implementation 
of libuv in details. We just want to understand how it works internally. And i have forgot many syntaxes in C. So there are some errors in the description
```
struct uv_loop_t {
    struct uv_handle_t** handles
    struct uv_request_t** requests
}

struct uv_handle_t {
    struct fd* file_descriptor
    (void *)(args**) callback
}

uv_run(uv_loop_t*);
```

The whole idea of event loop is trying to solve one problem: How to call some callback when there are data on certain file descritors? 

```
global List<Pair<FileDescriptor,CallbackFunction> queue;
class EventLoop {
  while(queue.isNotEmpty())
  {
    pair = queue.getNext();
    if(pair.fd.isDataAvailable())
    {
       pair.CallbackFunction(pair.fd.getData())
    }
  }
}
```




