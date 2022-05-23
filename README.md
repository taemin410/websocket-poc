# websocket-poc
Websocket C++ - Proof of Concept


## Docker Build environment setup

1. `docker-compose build` to build docker image 
2. run `docker-compose run --rm app bash` to run container with bash
3. Workspace folder src/ is injected into docker container. (You can edit the file on local editor. It will be synced to container workspace)
4. `mkdir -p build && cd build` and `cmake .. && make` to build. 
5. `./WebSocketPOC` to run the binary executable.
