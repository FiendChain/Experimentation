# use py tensorflow_basics.py
import tensorflow as tf

captcha_data = tf.keras.datasets.mnist

(input_train, output_train), (input_test, output_test) = captcha_data.load_data()

# sequential cascading multiperceptron neural network
model = tf.keras.models.Sequential([
    tf.keras.layers.Flatten(),
    tf.keras.layers.Dense(512, activation=tf.nn.relu),
    tf.keras.layers.Dropout(0.2),
    tf.keras.layers.Dense(10, activation=tf.nn.softmax)
])

# create the model
model.compile(optimizer='adam',
              loss="sparse_categorical_crossentropy",
              metrics=['accuracy'])

# train the model based on the training data
model.fit(input_train, output_train, epochs=5)

# calculate error in final model
model.evaluate(input_test, output_test)