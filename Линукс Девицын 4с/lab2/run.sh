docker build -t image-name .
docker run -d --name container-name image-name
docker cp container-name:info.txt info.txt
docker stop container-name
docker rm container-name