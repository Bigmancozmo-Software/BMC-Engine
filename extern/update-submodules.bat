cd glfw
git fetch
git pull https://github.com/glfw/glfw
cd ..

cd stb
git fetch
git pull
cd ..

cd glm
git fetch
git pull
cd ..

git add -A
git commit -am "Update submodules"
git push
