
################################################################################
# Variables
################################################################################
.PHONY: run trace build clean deploy default

default:
	@echo "docker"
	ruby --version
	gem --version
	bundle --version


# ________________________________________________________________________________
# DEVELOPMENT
# ________________________________________________________________________________
run:
	bundle exec jekyll serve --livereload

trace:
	bundle exec jekyll serve --livereload --trace

clean:
	bundle exec jekyll clean


# ________________________________________________________________________________
# PRODUCTION
# ________________________________________________________________________________
build:
	bundle exec jekyll build

# ________________________________________________________________________________
# DEPLOY
# ________________________________________________________________________________

deploy: build
	# get remote branches
	git fetch --all
	# the branch you want to overwrite
	git checkout gh 
	# reset to the new branch
	git reset --hard origin/master
	find . -maxdepth 1 ! -name _site ! -name .git -not -path '.' -exec rm -rf {} +
	mv _site/* ./
	rm -rf _site
	#  push to remote
	git push -f

