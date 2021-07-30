from flask import Flask

app = Flask(__name__)

@app.route("/")
def hello_world():
    print('LOL')
    return """<h1>Hello, my very best friend!</h1>
              <h2>Hello, my worse friend!</h2>"""


@app.route('/user/<username>')
def show_user_profile(username):
    return 'User %s' % username


def mean(sample):
    return sum(sample) / len(sample)


@app.route('/avg/<nums>')
def avg(nums):
    nums = nums.split(',')
    nums = [float(num) for num in nums]
    mean_nums = mean(nums)
    return 'AVG %s' % mean_nums
