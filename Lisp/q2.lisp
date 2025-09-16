(defun primo(x &optional (i 2))
    (block fim
        (if (= x 1)
            (return-from fim nil)
        )

        (if (= x i)
            t
            (if (= (mod x i) 0)
                nil
                (primo x (+ i 1))
            )
        )
    )
)

(defun nums (a b &optional (lista '()))
    (if (primo a)
        (if (= a b)
            (reverse (cons b lista))
            (nums (+ a 1) b (cons a lista))
        )
        (if (= a b)
            (reverse lista)
            (nums (+ a 1) b lista)
        )
    )
)
