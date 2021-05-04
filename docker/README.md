### Создание docker container (взятого из инета)
docker run -p 8888:8888 jupyter/scipy-notebook:17aba6048f44

### Зайти внутрь docker container
docker exec -it (id container) bash 

### Перекинуть данные в docker container
docker cp wine.data (id container):/home/jovyan/wine.data

### Подключение volume
docker run -v /Users/DOUBLEU/Documents/200K/EDUCATION/docker:/home/jovyan/ -p 8888:8888 jupyter/scipy-notebook:17aba6048f44

### Запуск из Dockerfile
docker build .
docker run -v /Users/DOUBLEU/Documents/200K/EDUCATION/docker:/home/jovyan/ -p 8888:8888 (id container)

### Задаем имя docker container
docker build  -t test .
docker run -v /Users/DOUBLEU/Documents/200K/EDUCATION/docker:/home/jovyan/ -p 8888:8888 test

### Запуск с помощью docker-compose
docker-compose up
docker-compose up --build - лучше так

### Пример docker-compose лежит в текущей директории



http://127.0.0.1:8888/?token=a663cda5d0ff4f15e3004423a31aedf87a5d7f8c48