; default grammar added
(set-logic BV)
(synth-fun inv((i (_ BitVec 32))(y (_ BitVec 32))(l (_ BitVec 32)))
 Bool
(( NTbool Bool)(NTnonbool (_ BitVec 32)))
((NTbool Bool((and NTbool NTbool)(or NTbool NTbool)(not NTbool)(= NTnonbool NTnonbool)(bvuge NTnonbool NTnonbool)(bvugt NTnonbool NTnonbool)))
(NTnonbool (_ BitVec 32)(i y l (_ bv0 32) (_ bv1 32) (_ bv2 32) (_ bv3 32)  (bvadd NTnonbool NTnonbool)(bvsub NTnonbool NTnonbool)(bvshl NTnonbool NTnonbool)(bvlshr NTnonbool NTnonbool)(bvurem NTnonbool NTnonbool)(ite NTbool NTnonbool NTnonbool)))

)
)

(declare-var i (_ BitVec 32))
(declare-var i1 (_ BitVec 32))
(declare-var l (_ BitVec 32))
(declare-var l1 (_ BitVec 32))
(declare-var x (_ BitVec 32))
(declare-var x1 (_ BitVec 32))
(declare-var y (_ BitVec 32))
(declare-var y1 (_ BitVec 32))
( constraint  (=> (or (or (bvult x (_ bv0 32)) (bvult y (_ bv0 32))) (bvugt y x)) true) ) 
( constraint  (=> (and (and (not (or (or (bvult x (_ bv0 32)) (bvult y (_ bv0 32))) (bvugt y x))) (= l x)) (= i (_ bv0 32))) (inv i y l )) ) 
( constraint  (=> (and (and (and (inv i y l ) (bvult i y)) (not (or (bvult i (_ bv0 32)) (bvuge i l)))) (= i1 (bvadd i (_ bv1 32)))) (inv i1 y l )) ) 
( constraint  (=> (and (and (inv i y l ) (bvult i y)) (or (bvult i (_ bv0 32)) (bvuge i l))) false) ) 
(check-synth)
