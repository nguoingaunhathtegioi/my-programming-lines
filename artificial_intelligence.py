import numpy as np
from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt

# 1. Sample Data
# Assume we have data on study hours (X) and test scores (y)
X = np.array([5, 15, 25, 35, 45, 55]).reshape((-1, 1)) # Study hours
y = np.array([5, 20, 14, 32, 22, 38]) # Test scores

# 2. Create a Linear Regression model
model = LinearRegression()

# 3. Train the model
model.fit(X, y)

# 4. Print model parameters
print(f"Intercept: {model.intercept_}")
print(f"Slope: {model.coef_[0]}")

# 5. Make predictions
y_pred = model.predict(X)
print(f"Predictions on training data: {y_pred}")

# Predict a new value
X_new = np.array([40]).reshape((-1, 1))
y_new_pred = model.predict(X_new)
print(f"Prediction for 40 hours of study: {y_new_pred[0]}")

# 6. Visualize the results
plt.scatter(X, y, color='blue', label='Actual Data')
plt.plot(X, y_pred, color='red', label='Regression Line')
plt.scatter(X_new, y_new_pred, color='green', marker='X', s=100, label='New Prediction')
plt.xlabel("Study Hours")
plt.ylabel("Test Scores")
plt.title("Linear Regression")
plt.legend()
plt.grid(True)
plt.show()
