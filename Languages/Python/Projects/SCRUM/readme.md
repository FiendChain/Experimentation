To run, enter into the virtualenv
# Creating virtual environment
Command: **virtualenv ./venv -p $(which python3.5)**

After creating the virtual environment, enter the virtual environment.

Linux: **. ./venv/bin/activate**

Windows: **. ./venv/Scripts/activate**

Then get the necessary python modules via: **pip install -r ./requirements.txt**

# Running server
After creating the virtual environment, and fetching all python dependencies via pip, run the server by executing **run.py**.

Linux: **python3.5 ./run.py**

Windows: **./run.py**


