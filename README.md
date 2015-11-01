ad.mesh.proj
cd C:/first
git init


git remote add origin/test https://github.com/nurlan095/ad.mesh.proj.git

вытащить все из репозитория
git pull origin/test master

создать что либо
touch README.md

добавить в репозиторий
git add README.md

закомитить
git commit -m "YOUR COMMENT"

отправить
git push origin/test master

статус, что бы посмотреть файлы 
git status

если много файлов
git add .
git commit -m "comment"
git push origin/test master
