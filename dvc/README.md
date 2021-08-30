# DVC

brew install dvc

mkdir dvc

cd dvc

git init

dvc init

mkdir data

dvc get https://github.com/iterative/dataset-registry \\nget-started/data.xml -o data/data.xml

dvc add data/data.xml

git add data/.gitignore data/data.xml.dvc

git commit -m 'add data'

dvc remote add -d storage gdrive://1UJS_xukVLCOHQmKBYjDdnZWeESSXmmqf

git add .dvc/config
git commit -m "Configure remote storage"

dvc push



dvc add data/data.xml

git add data/data.xml.dvc

git commit -m 'Double dataset'

dvc push



dvc pull



git checkout HEAD^1 data/data.xml.dvc

dvc checkout

