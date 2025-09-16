(defun lg (m n &optional (i 0) (origm m))
    (if (> m n)
        i
        (lg (* m origm) n ((+ i 1) origm))
    )
)