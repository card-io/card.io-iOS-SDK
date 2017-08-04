//
//  ViewController.swift
//  SampleApp-Swift
//
//  Copyright (c) 2014 PayPal. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

  @IBOutlet weak var resultLabel: UILabel!
  override func viewDidLoad() {
    super.viewDidLoad()
    // Do any additional setup after loading the view, typically from a nib.
    CardIOUtilities.preload()
  }

  override func didReceiveMemoryWarning() {
    super.didReceiveMemoryWarning()
    // Dispose of any resources that can be recreated.
  }
  
  @IBAction func scanCard(_ sender: Any) {
    if let cardIOVC = CardIOPaymentViewController(paymentDelegate: self) {
        cardIOVC.modalPresentationStyle = .formSheet
        present(cardIOVC, animated: true, completion: nil)
    } else {
        print("Something's not good.")
    }
  }
}

extension ViewController: CardIOPaymentViewControllerDelegate {
    func userDidCancel(_ paymentViewController: CardIOPaymentViewController) {
        self.resultLabel.text = "user canceled"
        paymentViewController.dismiss(animated: true, completion: nil)
    }

    func userDidProvide(_ cardInfo: CardIOCreditCardInfo, in paymentViewController: CardIOPaymentViewController) {
        let cardDetails = "Received card info.\n Number: \(cardInfo.redactedCardNumber)\n expiry: \(cardInfo.expiryMonth)/\(cardInfo.expiryYear)\n cvv: \(cardInfo.cvv)."
        self.resultLabel.text = cardDetails

        paymentViewController.dismiss(animated: true, completion: nil)
    }
}
