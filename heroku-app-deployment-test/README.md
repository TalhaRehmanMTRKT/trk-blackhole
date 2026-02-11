# heroku-app-deployment-test
 
This is a test project to deploy the Dash app on Heroku.

- Heroku Account
- Connecting Github, the repository that contains the Code of App.

- requirements.txt
using the following command in the terminal 
```
pip freeze > requirements.txt
```
- Procfile
inside the procfile
```
web: gunicorn app:server
```


## References
Dash - https://dash.plotly.com/
Heroku - https://www.Heroku.com/