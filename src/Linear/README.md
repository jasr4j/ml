## LOGIC FOR LINEAR REGRESSION (UNIVARIATE)

### BASELINE: 

y = mx + b

x is the predictor var.; y is the predicted var.

### LEAST SQUARES METHOD

residual = y<sub>1</sub> - ŷ<sub>1</sub>

Sum of Squared Errors = Σ(residual)<sup>2</sup>

Hypothesis Function: 

ŷ = h(x) = β<sub>0</sub> + (β<sub>0</sub>)x

β<sub>0</sub> is the y-intercept
β<sub>1</sub> is the slope

### ASSUMPTIONS

Linearity, Independence, Homoscedasticity (Errors have equal spread), Normality of Errors, No Autocorrelation, Additivity

### REGRESSION

ŷ = θ<sub>0</sub> + (θ<sub>1</sub>)x

[Predicted = Intercept + Slope * Input]

#### Mean Squared Error (MSE) LOSS FUNCTION

loss(J)= (1/n) * Σ<sup>i</sup><sub>n</sub>&nbsp;(ŷ<sub>i</sub> - y<sub>i</sub>)<sup>2</sup>

#### GRADIENT DESCENT

Using the MSE Loss Function, we can adjust θ<sub>0</sub> and θ<sub>1</sub>

1. Random Slope and Intercept Values
2. Calculate Error (between actual & predicted)
3. Gradient (how much each parameter adds to error)
4. Update the parameter to reduce error
5. Repeat until error is small as possible

##### UPDATE FORMULA

θ<sub>j</sub> := θ<sub>j</sub> − α (∂/∂θ<sub>j</sub>) J (θ<sub>0</sub>, θ<sub>1</sub>)

The algorithm is supposed to stop when the gradient becomes 0. 

Note: ∂ is the partial derivative symbol

#### ACCURACY

Mean Absolute Error (MAE): 

MAE = (1/n) * Σ<sup>n</sup><sub>i=1</sub>&nbsp;(|Y<sub>i</sub> - Ŷ<sub>i</sub>|)

Where n is the number of observations, Yi is the actual, and Ŷi is the predicted values

The lower the output of MAE, the better the regression (perfect is 0)




