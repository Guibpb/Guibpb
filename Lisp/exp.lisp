(defun expoente (a b)
    (if (= b 0)
        1
        (* a (expoente a (- b 1)))
    )
)   