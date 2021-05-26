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

### Запус приложения
$ docker build -t my-python-app .
$ docker run -it --rm --name my-running-app my-python-app